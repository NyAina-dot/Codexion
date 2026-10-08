/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:45:01 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/29 14:48:30 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	is_request_first(t_simulation *sim, t_coder *coder)
{
	return (sim->queue.size > 0
		&& sim->queue.requests[0].coder == coder);
}

static int	wait_for_request(t_coder *coder)
{
	t_simulation	*sim;
	struct timespec	timeout;

	sim = coder->sim;
	while (!sim->stop)
	{
		if (!is_request_first(sim, coder))
		{
			pthread_cond_wait(&sim->queue.cond, &sim->queue.mutex);
			continue ;
		}
		if (dongles_available(coder))
			return (1);
		if (get_wait_time(coder, &timeout) != 0)
			return (0);
		pthread_cond_timedwait(&sim->queue.cond,
			&sim->queue.mutex, &timeout);
	}
	return (0);
}

int	wait_for_turn(t_coder *coder)
{
	t_simulation	*sim;
	t_request		request;

	sim = coder->sim;
	pthread_mutex_lock(&sim->queue.mutex);
	if (wait_for_request(coder))
	{
		reserve_dongles(coder);
		queue_pop(sim, &request);
	}
	pthread_mutex_unlock(&sim->queue.mutex);
	return (0);
}

int	request_dongles(t_coder *coder)
{
	t_request	request;

	request.coder = coder;
	request.request_time = get_time_ms();
	request.deadline = coder->last_compile_time
		+ coder->sim->args.time_to_burnout;
	if (queue_push(coder->sim, request) != 0)
		return (1);
	return (wait_for_turn(coder));
}
