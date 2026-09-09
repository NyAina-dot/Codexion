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
	int	i;

	i = 0;
	if (ac >= 9)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}
	printf("%d\n", atoi(av[1]));
	return (0);
}
