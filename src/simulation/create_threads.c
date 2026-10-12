/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 10:53:34 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/10/12 21:23:07 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	stop_simulation(t_simulation *sim)
{
	pthread_mutex_lock(&sim->queue.mutex);
	sim->stop = 1;
	pthread_cond_broadcast(&sim->queue.cond);
	pthread_mutex_unlock(&sim->queue.mutex);
}

static int	start_monitor(t_simulation *sim)
{
	if (pthread_create(&sim->monitor_thread, NULL,
			monitor_routine, sim) != 0)
	{
		printf("Error: Failed to create monitor thread\n");
		stop_simulation(sim);
		return (1);
	}
	return (0);
}

static int	start_coders(t_simulation *sim, int *created)
{
	while (*created < sim->args.number_of_coders)
	{
		if (pthread_create(&sim->coders[*created].thread,
				NULL, coders_routine,
				&sim->coders[*created]) != 0)
		{
			printf("Error: Failed to create coder thread\n");
			stop_simulation(sim);
			return (1);
		}
		(*created)++;
	}
	return (0);
}

static int	join_coders(t_simulation *sim, int created)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < created)
	{
		if (pthread_join(sim->coders[i].thread, NULL) != 0)
			error = 1;
		i++;
	}
	return (error);
}

int	create_threads(t_simulation *sim)
{
	int	created;
	int	error;

	created = 0;
	if (start_monitor(sim) != 0)
		return (1);
	error = start_coders(sim, &created);
	if (join_coders(sim, created) != 0)
		error = 1;
	if (pthread_join(sim->monitor_thread, NULL) != 0)
		error = 1;
	return (error);
}
