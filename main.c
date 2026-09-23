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

static int	test_queue(t_simulation *sim)
{
	t_request	request;

	if (sim->args.number_of_coders < 3)
	{
		printf("Queue test requires at least 3 coders\n");
		return (1);
	}
	if (init_queue(sim) != 0)
		return (1);
	if (strcmp(sim->args.scheduler, "edf") == 0)
	{
		queue_push(sim, (t_request){&sim->coders[0], 300, 100});
		queue_push(sim, (t_request){&sim->coders[1], 100, 300});
		queue_push(sim, (t_request){&sim->coders[2], 200, 200});
	}
	else
	{
		queue_push(sim, (t_request){&sim->coders[0], 300, 500});
		queue_push(sim, (t_request){&sim->coders[1], 100, 200});
		queue_push(sim, (t_request){&sim->coders[2], 200, 300});
	}
	while (queue_pop(sim, &request) == 0)
		printf("Popped coder: %d\n", request.coder->id);
	free(sim->queue.requests);
	sim->queue.requests = NULL;
	return (0);
}

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
	if (init_coders(&sim) != 0)
		return (1);
	if (test_queue(&sim) != 0)
	{
		cleanup_simulation(&sim);
		return (1);
	}
	cleanup_simulation(&sim);
	return (0);
}
