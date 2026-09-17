/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 08:46:31 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/17 10:21:18 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

long	ft_atol(const char *str)
{
	long	result;
	int		digit;

	result = 0;
	while (ft_isspace(*str))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		if (result > (LONG_MAX - digit) / 10)
			return (-1);
		result = result * 10 + digit;
		str++;
	}
	return (result);
}
