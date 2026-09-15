#include "codexion.h"

int	allocate_coders(t_simulation *sim)
{
	sim->coders = malloc(sizeof(t_coder)
            * sim->args.number_of_coders);
	if (!sim->coders)
		return (1);
	return (0);
}
