/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_dongles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 09:52:01 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/15 09:57:52 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	allocate_dongles(t_simulation *sim)
{
	sim->dongles = malloc(sizeof(t_dongle)
			* sim->args.number_of_coders);
	if (!sim->dongles)
		return (1);
	return (0);
}
