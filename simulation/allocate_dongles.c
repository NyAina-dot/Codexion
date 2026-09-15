#include "codexion.h"

int allocate_dongles(t_simulation *sim)
{
    sim->dongles = malloc(sizeof(t_dongle)
            * sim->args.number_of_coders);
    if (!sim->dongles)
        return (1);
    return (0);
}
