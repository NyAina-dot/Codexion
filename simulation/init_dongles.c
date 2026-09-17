/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dongles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 09:52:38 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/17 10:16:16 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_dongles(t_simulation *sim)
{
	int	i;

	if (allocate_dongles(sim) != 0)
		return (1);
	i = 0;
	while (i < sim->args.number_of_coders)
	{
		if (pthread_mutex_init(&sim->dongles[i].mutex, NULL) != 0)
			return (1);
		sim->dongles[i].available_at = 0;
		sim->dongles_initialized++;
		i++;
	}
	return (0);
}
