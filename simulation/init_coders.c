#include "codexion.h"

int init_coders(t_simulation *sim)
{
    int i;

    if (allocate_coders(sim) != 0)
        return (1);
    i = 0;
    while (i < sim->args.number_of_coders)
    {
        sim->coders[i].id = i + 1;
        sim->coders[i].compiles_done = 0;
        sim->coders[i].last_compile_time = 0;
        i++;
    }
    return (0);
}
