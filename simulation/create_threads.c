/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 10:53:34 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/18 13:03:11 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coders_routine(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	printf("coder %d started\n", coder->id);
	coder_compile(coder);
	coder_debug(coder);
	coder_refactor(coder);
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
