/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 21:25:18 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/10/12 21:25:35 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coders_routine(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	printf("coder %d started\n", coder->id);
	while (coder->compiles_done
		< coder->sim->args.number_of_compiles_required)
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
