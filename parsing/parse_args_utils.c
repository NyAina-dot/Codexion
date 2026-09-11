/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 08:46:49 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/11 09:37:04 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	print_usage(void)
{
	printf(
		"Error: Invalid arguments\n"
		"Usage: ./codexion <number_of_coders> "
		"<time_to_burnout> <time_to_compile> "
		"<time_to_debug> <time_to_refactor> "
		"<number_of_compiles_required> "
		"<dongle_cooldown> <scheduler>\n"
		);
}

int	is_valid_number_of_coders(int number_of_coders)
{
	return (number_of_coders > 0);
}

int	is_valid_time_value(long time_value)
{
	return (time_value > 0);
}

int	is_valid_number_of_compiles_required(int count)
{
	return (count > 0);
}

int	is_valid_scheduler(char *scheduler)
{
	return (
		strcmp(scheduler, "edf") == 0
		|| strcmp(scheduler, "fifo") == 0
	);
}
