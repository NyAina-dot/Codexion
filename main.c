/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 09:57:59 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/09 10:58:56 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int ac, char **av)
{
	t_args	args;
	int		i;

	if (ac != 9)
	{
		print_usage();
		return (1);
	}
	i = 1;
	while (i < 8)
	{
		if (!is_number(av[i]))
		{
			printf("Error: Invalid argument, '%s' must be a positive integer\n", av[i]);
			return (1);
		}
		i++;
	}
	parse_args(av, &args);
	i = is_valid_args(&args);
	if (i != 0)
	{
		print_arg_error(i);
		return (1);
	}
	printf("All arguments are valid. Proceeding with the program...\n");

	return (0);
}
