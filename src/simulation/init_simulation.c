/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 09:52:48 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/10/12 21:48:43 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_simulation(t_simulation *sim, t_args *args)
{
	sim->args = *args;
	sim->coders = NULL;
	sim->dongles = NULL;
	sim->queue.requests = NULL;
	sim->queue.size = 0;
	sim->queue.capacity = 0;
	sim->start_time = 0;
	sim->stop = 0;
	sim->dongles_initialized = 0;
	sim->queue.mutex_initialized = 0;
	sim->queue.cond_initialized = 0;
	return (0);
}

int	init_simulation_data(t_simulation *sim)
{
	if (init_coders(sim) != 0)
	{
		printf("Error: Failed to initialize coders\n");
		return (1);
	}
	if (init_dongles(sim) != 0)
	{
		printf("Error: Failed to initialize dongles\n");
		return (1);
	}
	return (0);
}
