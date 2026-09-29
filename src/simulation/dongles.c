/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 08:45:40 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/29 13:39:56 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	take_dongles(t_coder *coder)
{
	int	first;
	int	second;

	first = coder->left_dongle;
	second = coder->right_dongle;
	if (first > second)
	{
		first = coder->right_dongle;
		second = coder->left_dongle;
	}
	pthread_mutex_lock(&coder->sim->dongles[first].mutex);
	printf("Coder %d took dongle %d\n", coder->id, first);
	pthread_mutex_lock(&coder->sim->dongles[second].mutex);
	printf("Coder %d took dongle %d\n", coder->id, second);
}

void	release_dongles(t_coder *coder)
{
	long	available_at;
	int		first;
	int		second;

	available_at = get_time_ms() + coder->sim->args.dongle_cooldown;
	first = coder->left_dongle;
	second = coder->right_dongle;
	if (first > second)
	{
		first = coder->right_dongle;
		second = coder->left_dongle;
	}
	coder->sim->dongles[first].available_at = available_at;
	coder->sim->dongles[second].available_at = available_at;
	pthread_mutex_unlock(&coder->sim->dongles[second].mutex);
	pthread_mutex_unlock(&coder->sim->dongles[first].mutex);
	pthread_mutex_lock(&coder->sim->queue.mutex);
	pthread_cond_broadcast(&coder->sim->queue.cond);
	pthread_mutex_unlock(&coder->sim->queue.mutex);
}

int	dongles_available(t_coder *coder)
{
	long	now;

	now = get_time_ms();
	if (coder->sim->dongles[coder->left_dongle].available_at > now)
		return (0);
	if (coder->sim->dongles[coder->right_dongle].available_at > now)
		return (0);
	return (1);
}
