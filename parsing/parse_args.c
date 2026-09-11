/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 08:47:06 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/11 11:01:23 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	parse_args(char **av, t_args *args)
{
	args->number_of_coders = atoi(av[1]);
	args->time_to_burnout = ft_atol(av[2]);
	args->time_to_compile = ft_atol(av[3]);
	args->time_to_debug = ft_atol(av[4]);
	args->time_to_refactor = ft_atol(av[5]);
	args->number_of_compiles_required = atoi(av[6]);
	args->dongle_cooldown = ft_atol(av[7]);
	args->scheduler = av[8];
}

int	is_valid_args(t_args *args)
{
	if (!is_valid_number_of_coders(args->number_of_coders))
		return (1);
	if (!is_valid_time_value(args->time_to_burnout))
		return (2);
	if (!is_valid_time_value(args->time_to_compile))
		return (3);
	if (!is_valid_time_value(args->time_to_debug))
		return (4);
	if (!is_valid_time_value(args->time_to_refactor))
		return (5);
	if (!is_valid_number_of_compiles_required(
			args->number_of_compiles_required))
		return (6);
	if (!is_valid_time_value(args->dongle_cooldown))
		return (7);
	if (!is_valid_scheduler(args->scheduler))
		return (8);
	return (0);
}

void	print_arg_error(int error)
{
	if (error == 1)
		printf("Error: number_of_coders must be greater than 0\n");
	else if (error == 2)
		printf("Error: time_to_burnout must be greater than 0\n");
	else if (error == 3)
		printf("Error: time_to_compile must be greater than 0\n");
	else if (error == 4)
		printf("Error: time_to_debug must be greater than 0\n");
	else if (error == 5)
		printf("Error: time_to_refactor must be greater than 0\n");
	else if (error == 6)
		printf("Error: number_of_compiles_required must be greater than 0\n");
	else if (error == 7)
		printf("Error: dongle_cooldown must be greater than 0\n");
	else if (error == 8)
		printf("Error: scheduler must be 'fifo' or 'edf'\n");
}
