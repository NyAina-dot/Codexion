/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 10:53:34 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/10/08 16:08:38 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coders_routine(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	printf("coder %d started\n", coder->id);
	while (coder->compiles_done
		< coder->sim->args.number_of_compiles_required)
	{
		if (simulation_stopped(coder->sim))
			break ;
		if (!coder_compile(coder))
			break ;
		pthread_mutex_lock(&coder->sim->queue.mutex);
		coder->compiles_done++;
		pthread_mutex_unlock(&coder->sim->queue.mutex);
		if (simulation_stopped(coder->sim))
			break ;
		coder_debug(coder);
		coder_refactor(coder);
	}
	return (NULL);
}

int	create_threads(t_simulation *sim)
{
	int	nb_coders;
	int	i;

	nb_coders = sim->args.number_of_coders;
	pthread_create(&sim->monitor_thread, NULL, monitor_routine, sim);
	i = 0;
	while (i < nb_coders)
	{
		pthread_create(
			&sim->coders[i].thread, NULL, coders_routine,
			&sim->coders[i]
			);
		i++;
	}
	i = 0;
	while (i < nb_coders)
	{
		pthread_join(sim->coders[i].thread, NULL);
		i++;
	}
	pthread_join(sim->monitor_thread, NULL);
	return (0);
}
