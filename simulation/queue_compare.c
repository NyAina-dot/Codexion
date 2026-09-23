#include "codexion.h"

int	request_has_priority(t_simulation *sim, t_request *a, t_request *b)
{
	long	value_a;
	long	value_b;

	if (strcmp(sim->args.scheduler, "edf") == 0)
	{
		value_a = a->deadline;
		value_b = b->deadline;
	}
	else
	{
		value_a = a->request_time;
		value_b = b->request_time;
	}
	if (value_a != value_b)
		return (value_a < value_b);
	return (a->coder->id < b->coder->id);
}
