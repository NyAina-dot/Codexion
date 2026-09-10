/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 10:03:13 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/09 12:03:07 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_args
{
	int		number_of_coders;
	long	time_to_burnout;
	long	time_to_compile;
	long	time_to_debug;
	long	time_to_refactor;
	int		number_of_compiles_required;
	long	dongle_cooldown;
	char	*scheduler;
}	t_args;

typedef struct s_coder
{
	int	id;
}	t_coder;

typedef struct s_dongle
{
	pthread_mutex_t	mutex;
	long available_at;
}	t_dongle;

int		is_number(char *str);
void	parse_args(char **av, t_args *args);
int 	ft_isspace(char c);
long	ft_atol(const char *str);
void	print_usage();
int 	is_valid_number_of_coders(int number_of_coders);
int 	is_valid_time_value(long time_value);
int 	is_valid_number_of_compiles_required(int count);
int 	is_valid_scheduler(char *scheduler);
int		is_valid_args(t_args *args);
void	print_arg_error(int error);

#endif