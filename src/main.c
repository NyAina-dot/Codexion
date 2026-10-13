/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 09:57:59 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/10/12 22:00:34 by nyrajaon         ###   ########.fr       */
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
			printf("Error: Invalid argument, "
				"'%s' must be an integer\n", av[i]);
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
	int				error;

	if (ac != 9)
		return (print_usage(), 1);
	if (!validate_number_args(av))
		return (1);
	parse_args(av, &args);
	error = is_valid_args(&args);
	if (error != 0)
		return (print_arg_error(error), 1);
	if (init_simulation(&sim, &args) != 0)
		return (1);
	sim.start_time = get_time_ms();
	if (init_simulation_data(&sim) != 0)
		return (cleanup_simulation(&sim), 1);
	if (init_queue(&sim) != 0)
		return (cleanup_simulation(&sim), 1);
	error = create_threads(&sim);
	cleanup_simulation(&sim);
	if (error != 0)
		return (1);
	return (0);
}
