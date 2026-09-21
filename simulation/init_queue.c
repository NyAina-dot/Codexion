/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:44:28 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/21 14:01:55 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_queue(t_simulation *sim)
{
	sim->queue.requests = NULL;
	sim->queue.capacity = 0;
	sim->queue.size = 0;
	return (0);
}
