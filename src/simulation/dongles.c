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
	long			available_at;
	int				first;
	int				second;

	available_at = get_time_ms() + coder->sim->args.dongle_cooldown;
	first = coder->left_dongle;
	second = coder->right_dongle;
	if (first > second)
	{
		first = coder->right_dongle;
		second = coder->left_dongle;
	}
	pthread_mutex_lock(&coder->sim->queue.mutex);
	coder->sim->dongles[first].available_at = available_at;
	coder->sim->dongles[second].available_at = available_at;
	coder->sim->dongles[first].in_use = 0;
	coder->sim->dongles[second].in_use = 0;
	pthread_mutex_unlock(&coder->sim->dongles[second].mutex);
	pthread_mutex_unlock(&coder->sim->dongles[first].mutex);
	pthread_cond_broadcast(&coder->sim->queue.cond);
	pthread_mutex_unlock(&coder->sim->queue.mutex);
}

int	dongles_available(t_coder *coder)
{
	t_dongle	*left;
	t_dongle	*right;
	long		now;

	left = &coder->sim->dongles[coder->left_dongle];
	right = &coder->sim->dongles[coder->right_dongle];
	now = get_time_ms();
	if (left->in_use || right->in_use)
		return (0);
	if (left->available_at > now || right->available_at > now)
		return (0);
	return (1);
}

long	next_dongles_available(t_coder *coder)
{
	long	left;
	long	right;

	left = coder->sim->dongles[coder->left_dongle].available_at;
	right = coder->sim->dongles[coder->right_dongle].available_at;
	if (left > right)
		return (left);
	return (right);
}

int	get_wait_time(t_coder *coder, struct timespec *timeout)
{
	long	wait_ms;

	wait_ms = next_dongles_available(coder) - get_time_ms();
	if (wait_ms < 0)
		wait_ms = 0;
	if (clock_gettime(CLOCK_REALTIME, timeout) != 0)
		return (1);
	timeout->tv_sec += wait_ms / 1000;
	timeout->tv_nsec += (wait_ms % 1000) * 1000000L;
	if (timeout->tv_nsec >= 1000000000L)
	{
		timeout->tv_sec++;
		timeout->tv_nsec -= 1000000000L;
	}
	return (0);
}

void	reserve_dongles(t_coder *coder)
{
	t_simulation	*sim;

	sim = coder->sim;
	sim->dongles[coder->left_dongle].in_use = 1;
	sim->dongles[coder->right_dongle].in_use = 1;
}
