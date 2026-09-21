/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:06:39 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/21 15:26:37 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	queue_push(t_simulation *sim, t_requests request)
{
	int	i;

	i = 0;
	while (i < sim->queue.size)
	{
		sim->queue.requests[sim->queue.size] = request;
		sim->queue.size++;
	}
	return (0);
}
