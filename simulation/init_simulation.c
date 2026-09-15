#include "codexion.h"

int init_simulation(t_simulation *sim, t_args *args)
{
    sim->args = *args;
    sim->coders = NULL;
    sim->dongles = NULL;
    sim->start_time = 0;
    sim->stop = 0;
    return (0);
}
