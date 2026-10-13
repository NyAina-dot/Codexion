/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 21:25:18 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/10/12 22:06:42 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	coder_has_compiles_left(t_coder *coder)
{
	int	compiles_done;

	pthread_mutex_lock(&coder->sim->queue.mutex);
	compiles_done = coder->compiles_done;
	pthread_mutex_unlock(&coder->sim->queue.mutex);
	return (compiles_done
		< coder->sim->args.number_of_compiles_required);
}

void	*coders_routine(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	printf("coder %d started\n", coder->id);
    while (coder_has_compiles_left(coder))
	{
		if (simulation_stopped(coder->sim))
			break ;
		if (!coder_compile(coder))
			break ;
		pthread_mutex_lock(&coder->sim->queue.mutex);
		coder->compiles_done++;
		pthread_mutex_unlock(&coder->sim->queue.mutex);
		if (simulation_stopped(coder->sim))
			break ;
		coder_debug(coder);
		if (simulation_stopped(coder->sim))
			break ;
		coder_refactor(coder);
	}
	return (NULL);
}
