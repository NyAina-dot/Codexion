/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 08:46:00 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/21 09:54:44 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	coder_compile(t_coder *coder)
{
	take_dongles(coder);
	printf("coder %d compiling\n", coder->id);
	usleep(coder->sim->args.time_to_compile * 1000);
	release_dongles(coder);
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
