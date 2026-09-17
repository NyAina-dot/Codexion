/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 09:57:59 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/17 13:18:12 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	validate_number_args(char **av)
{
	int	i;

	i = 1;
	while (i < 8)
	{
		if (!is_number(av[i]))
		{
			printf(
				"Error: Invalid argument, "
				"'%s' must be an integer\n", av[i]
				);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_args			args;
	t_simulation	sim;
	int				i;

	if (ac != 9)
		return (print_usage(), 1);
	if (!validate_number_args(av))
		return (1);
	parse_args(av, &args);
	i = is_valid_args(&args);
	if (i != 0)
		return (print_arg_error(i), 1);
	if (init_simulation(&sim, &args) != 0)
	{
		printf("Error: Failed to initialize simulation\n");
		return (1);
	}
	if (init_simulation_data(&sim) != 0)
		return (1);
	if (create_threads(&sim) != 0)
		return (1);
	cleanup_simulation(&sim);
	return (0);
}
