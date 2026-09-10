#include "codexion.h"

void	print_usage()
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

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int is_valid_number_of_coders(int number_of_coders)
{
	return (number_of_coders > 0);
}

int is_valid_time_value(long time_value)
{
	return (time_value > 0);
}

int is_valid_number_of_compiles_required(int count)
{
	return (count > 0);
}

int is_valid_scheduler(char *scheduler)
{
	return (
		strcmp(scheduler, "edf") == 0
		|| strcmp(scheduler, "fifo") == 0
	);
}
