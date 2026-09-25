/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:06:39 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/25 12:50:51 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	queue_push(t_simulation *sim, t_request request)
{
	pthread_mutex_lock(&sim->queue.mutex);
	if (sim->queue.size >= sim->queue.capacity)
	{
		pthread_mutex_unlock(&sim->queue.mutex);
		return (1);
	}
	sim->queue.requests[sim->queue.size] = request;
	sim->queue.size++;
	heapify_up(sim, sim->queue.size - 1);
	pthread_cond_broadcast(&sim->queue.cond);
	pthread_mutex_unlock(&sim->queue.mutex);
	return (0);
}
