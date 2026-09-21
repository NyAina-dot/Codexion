/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 09:52:28 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/18 12:45:02 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_coders(t_simulation *sim)
{
	int	i;

	if (allocate_coders(sim) != 0)
		return (1);
	i = 0;
	while (i < sim->args.number_of_coders)
	{
		sim->coders[i].id = i + 1;
		sim->coders[i].compiles_done = 0;
		sim->coders[i].last_compile_time = 0;
		sim->coders[i].sim = sim;
		sim->coders[i].left_dongle = i;
		sim->coders[i].right_dongle = (i + 1)
			% sim->args.number_of_coders;
		i++;
	}
	return (0);
}
