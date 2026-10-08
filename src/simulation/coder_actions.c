/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 08:46:00 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/10/08 16:05:57 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	coder_compile(t_coder *coder)
{
	if (request_dongles(coder) != 0)
		return (0);
	if (simulation_stopped(coder->sim))
	{
		release_dongles(coder);
		return (0);
	}
	pthread_mutex_lock(&coder->sim->queue.mutex);
	coder->last_compile_time = get_time_ms();
	pthread_mutex_unlock(&coder->sim->queue.mutex);
	printf("coder %d compiling\n", coder->id);
	usleep(coder->sim->args.time_to_compile * 1000);
	release_dongles(coder);
	return (1);
}

void	coder_debug(t_coder *coder)
{
	printf("coder %d debugging\n", coder->id);
	usleep(coder->sim->args.time_to_debug * 1000);
}

void	coder_refactor(t_coder *coder)
{
	printf("coder %d refactoring\n", coder->id);
	usleep(coder->sim->args.time_to_refactor * 1000);
}
