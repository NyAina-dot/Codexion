#include "codexion.h"

int	queue_pop(t_simulation *sim, t_request *request)
{
	if (sim->queue.size == 0)
		return (1);
	*request = sim->queue.requests[0];
	sim->queue.size--;
	if (sim->queue.size > 0)
	{
		sim->queue.requests[0] = sim->queue.requests[sim->queue.size];
		heapify_down(sim, 0);
	}
	return (0);
}
