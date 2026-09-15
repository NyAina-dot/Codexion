#include "codexion.h"

void    cleanup_simulation(t_simulation *sim)
{
    if (sim->coders != NULL)
    {
        free(sim->coders);
        sim->coders = NULL;
    }
    if (sim->dongles != NULL)
    {
        free(sim->dongles);
        sim->dongles = NULL;
    }
}
