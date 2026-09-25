/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:44:28 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/25 10:27:41 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_queue(t_simulation *sim)
{
	sim->queue.capacity = sim->args.number_of_coders;
	sim->queue.size = 0;
	sim->queue.requests = malloc(sizeof(t_request) * sim->queue.capacity);
	if (!sim->queue.requests)
		return (1);
	if (pthread_cond_init(&sim->queue.cond, NULL) != 0)
	{
		pthread_mutex_destroy(&sim->queue.mutex);
		free(sim->queue.requests);
		sim->queue.requests = NULL;
		return (1);
	}
	return (0);
}
