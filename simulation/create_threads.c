/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 10:53:34 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/17 13:56:44 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coders_routine(void *arg)
{
	int	id;

	id = *(int *)arg;
	printf("Coder %d started\n", id);
	return (NULL);
}

int	create_threads(t_simulation *sim)
{
	int	nb_coders;
	int	i;

	nb_coders = sim->args.number_of_coders;
	i = 0;
	while (i < nb_coders)
	{
		pthread_create(
			&sim->coders[i].thread, NULL, coders_routine,
			&sim->coders[i].id
			);
		i++;
	}
	i = 0;
	while (i < nb_coders)
	{
		pthread_join(sim->coders[i].thread, NULL);
		i++;
	}
	return (0);
}
