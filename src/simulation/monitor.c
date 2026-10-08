/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:59:35 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/10/08 16:16:15 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	simulation_stopped(t_simulation *sim)
{
	int	stop;

	pthread_mutex_lock(&sim->queue.mutex);
	stop = sim->stop;
	pthread_mutex_unlock(&sim->queue.mutex);
	return (stop);
}

static int	all_coders_done(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->args.number_of_coders)
	{
		if (sim->coders[i].compiles_done
			< sim->args.number_of_compiles_required)
			return (0);
		i++;
	}
	return (1);
}

static int	check_burnout(t_simulation *sim)
{
	long	now;
	int		i;

	now = get_time_ms();
	i = 0;
	while (i < sim->args.number_of_coders)
	{
        if (sim->coders[i].compiles_done
	        < sim->args.number_of_compiles_required
	        && now - sim->coders[i].last_compile_time
		    >= sim->args.time_to_burnout)
		{
			printf("Coder %d burned out\n", sim->coders[i].id);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_simulation	*sim;
	int				stop;

	sim = (t_simulation *)arg;
	while (1)
	{
		pthread_mutex_lock(&sim->queue.mutex);
		stop = sim->stop;
		if (!stop && all_coders_done(sim))
			sim->stop = 1;
		if (!sim->stop && check_burnout(sim))
			sim->stop = 1;
		if (sim->stop)
			pthread_cond_broadcast(&sim->queue.cond);
		stop = sim->stop;
		pthread_mutex_unlock(&sim->queue.mutex);
		if (stop)
			break ;
		usleep(1000);
	}
	return (NULL);
}
