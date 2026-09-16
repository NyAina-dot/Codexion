#include "codexion.h"

void    cleanup_simulation(t_simulation *sim)
{
    if (sim->dongles != NULL)
    {
        int i;

        i = 0;
        while (i < sim->dongles_initialized)
        {
            pthread_mutex_destroy(&sim->dongles[i].mutex);
            i++;
        }
        free(sim->dongles);
        sim->dongles = NULL;
    }
    if (sim->coders != NULL)
    {
        free(sim->coders);
        sim->coders = NULL;
    }
}
