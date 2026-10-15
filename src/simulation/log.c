/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:42:23 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/10/15 11:42:35 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	print_log(t_coder *coder, char *message)
{
	long	timestamp;

	pthread_mutex_lock(&coder->sim->queue.mutex);
	timestamp = get_time_ms() - coder->sim->start_time;
	printf("%ld %d %s\n", timestamp, coder->id, message);
	pthread_mutex_unlock(&coder->sim->queue.mutex);
}
