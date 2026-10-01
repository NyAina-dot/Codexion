/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 12:17:56 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/10/01 13:58:15 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	get_wait_time(t_coder *coder, struct timespec *timeout)
{
	long			wait_ms;
	struct timeval	tv;

	wait_ms = next_dongles_available(coder) - get_time_ms();
	if (wait_ms < 0)
		wait_ms = 0;
	if (gettimeofday(&tv, NULL) != 0)
		return (1);
	timeout->tv_sec = tv.tv_sec;
	timeout->tv_nsec = (long)tv.tv_usec * 1000L;
	timeout->tv_sec += wait_ms / 1000;
	timeout->tv_nsec += (wait_ms % 1000) * 1000000L;
	if (timeout->tv_nsec >= 1000000000L)
	{
		timeout->tv_sec++;
		timeout->tv_nsec -= 1000000000L;
	}
	return (0);
}
