#include "codexion.h"

int init_dongles(t_simulation *sim)
{
    int i;
    if (allocate_dongles(sim) != 0)
        return (1);
    i = 0;
    while (i < sim->args.number_of_coders)
    {
        if (pthread_mutex_init(&sim->dongles[i].mutex, NULL) != 0)
            return (1);
        sim->dongles[i].available_at = 0;
        i++;
    }
    return (0);
}
