/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:44:28 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/10/12 21:43:19 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_queue(t_simulation *sim)
{
	sim->queue.capacity = sim->args.number_of_coders;
	sim->queue.size = 0;
	sim->queue.requests = malloc(
			sizeof(t_request) * sim->queue.capacity);
	if (!sim->queue.requests)
		return (1);
	if (pthread_mutex_init(&sim->queue.mutex, NULL) != 0)
		return (1);
	sim->queue.mutex_initialized = 1;
	if (pthread_cond_init(&sim->queue.cond, NULL) != 0)
		return (1);
	sim->queue.cond_initialized = 1;
	return (0);
}
