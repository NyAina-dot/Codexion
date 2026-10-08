/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_dongle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 20:08:33 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/10/08 20:10:18 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	release_one_dongle(t_coder *coder, long available_at)
{
	int	index;

	index = coder->left_dongle;
	pthread_mutex_lock(&coder->sim->queue.mutex);
	coder->sim->dongles[index].available_at = available_at;
	coder->sim->dongles[index].in_use = 0;
	pthread_cond_broadcast(&coder->sim->queue.cond);
	pthread_mutex_unlock(&coder->sim->queue.mutex);
	pthread_mutex_unlock(&coder->sim->dongles[index].mutex);
}
