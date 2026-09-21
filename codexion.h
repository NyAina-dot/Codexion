/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 10:03:13 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/18 13:01:52 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_simulation t_simulation;

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
	int				id;
	int				compiles_done;
	long			last_compile_time;
	pthread_t		thread;
	t_simulation	*sim;
	int				left_dongle;
	int				right_dongle;
}	t_coder;

typedef struct s_dongle
{
	pthread_mutex_t	mutex;
	long			available_at;
}	t_dongle;

typedef struct s_simulation
{
	t_args		args;
	t_coder		*coders;
	t_dongle	*dongles;
	long		start_time;
	int			stop;
	int			dongles_initialized;
}	t_simulation;

int		is_number(char *str);
void	parse_args(char **av, t_args *args);
int		ft_isspace(char c);
long	ft_atol(const char *str);
void	print_usage(void);
int		is_valid_number_of_coders(int number_of_coders);
int		is_valid_time_value(long time_value);
int		is_valid_number_of_compiles_required(int count);
int		is_valid_scheduler(char *scheduler);
int		is_valid_args(t_args *args);
void	print_arg_error(int error);
int		validate_number_args(char **av);
int		init_simulation(t_simulation *sim, t_args *args);
int		allocate_coders(t_simulation *sim);
int		init_coders(t_simulation *sim);
int		allocate_dongles(t_simulation *sim);
int		init_dongles(t_simulation *sim);
void	cleanup_simulation(t_simulation *sim);
int		init_simulation_data(t_simulation *sim);
long	get_time_ms(void);
int		create_threads(t_simulation *sim);
void	*coders_routine(void *arg);
void	coder_compile(t_coder *coder);
void	coder_debug(t_coder *coder);
void	coder_refactor(t_coder *coder);
void	take_dongles(t_coder *coder);
void	release_dongles(t_coder *coder);

#endif