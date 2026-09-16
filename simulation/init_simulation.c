#include "codexion.h"

int init_simulation(t_simulation *sim, t_args *args)
{
    sim->args = *args;
    sim->coders = NULL;
    sim->dongles = NULL;
    sim->start_time = 0;
    sim->stop = 0;
    sim->dongles_initialized = 0;
    return (0);
}

int	init_simulation_data(t_simulation *sim)
{
	if (init_coders(sim) != 0)
	{
		printf("Error: Failed to initialize coders\n");
		cleanup_simulation(sim);
		return (1);
	}
	if (init_dongles(sim) != 0)
	{
		printf("Error: Failed to initialize dongles\n");
		cleanup_simulation(sim);
		return (1);
	}
	return (0);
}
