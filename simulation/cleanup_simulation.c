/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 09:52:16 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/17 10:30:37 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	cleanup_simulation(t_simulation *sim)
{
	int	i;

	if (sim->dongles != NULL)
	{
		i = 0;
		while (i < sim->dongles_initialized)
		{
			pthread_mutex_destroy(&sim->dongles[i].mutex);
			i++;
		}
		free(sim->dongles);
		sim->dongles = NULL;
	}
	if (sim->coders != NULL)
	{
		free(sim->coders);
		sim->coders = NULL;
	}
}
