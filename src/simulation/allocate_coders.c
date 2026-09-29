/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_coders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 09:51:45 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/29 11:15:09 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	allocate_coders(t_simulation *sim)
{
	sim->coders = malloc(sizeof(t_coder)
			* sim->args.number_of_coders);
	if (!sim->coders)
		return (1);
	return (0);
}
