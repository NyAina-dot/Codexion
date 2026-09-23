/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:06:39 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/23 08:52:27 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	queue_push(t_simulation *sim, t_request request)
{
	if (sim->queue.size >= sim->queue.capacity)
		return (1);
	sim->queue.requests[sim->queue.size] = request;
	sim->queue.size++;
	heapify_up(sim, sim->queue.size - 1);
	return (0);
}
