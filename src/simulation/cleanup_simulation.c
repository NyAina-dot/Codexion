/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 09:52:16 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/10/13 07:51:42 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	free_coders(t_simulation *sim)
{
	if (sim->coders)
	{
		free(sim->coders);
		sim->coders = NULL;
		return (1);
	}
	return (0);
}

void	cleanup_simulation(t_simulation *sim)
{
	int	i;

	if (sim->dongles)
	{
		i = 0;
		while (i < sim->dongles_initialized)
		{
			pthread_mutex_destroy(&sim->dongles[i].mutex);
			i++;
		}
		free(sim->dongles);
		sim->dongles = NULL;
		sim->dongles_initialized = 0;
	}
	free_coders(sim);
	if (sim->queue.cond_initialized)
	{
		pthread_cond_destroy(&sim->queue.cond);
		sim->queue.cond_initialized = 0;
	}
	if (sim->queue.mutex_initialized)
	{
		pthread_mutex_destroy(&sim->queue.mutex);
		sim->queue.mutex_initialized = 0;
	}
	free(sim->queue.requests);
	sim->queue.requests = NULL;
}
