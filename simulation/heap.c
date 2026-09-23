#include "codexion.h"

void	heapify_up(t_simulation *sim, int index)
{
	int			parent;
	t_request	temp;

	while (index > 0)
	{
		parent = (index - 1) / 2;
		if (!request_has_priority(sim, &sim->queue.requests[index],
				&sim->queue.requests[parent]))
			break ;
		temp = sim->queue.requests[index];
		sim->queue.requests[index] = sim->queue.requests[parent];
		sim->queue.requests[parent] = temp;
		index = parent;
	}
}

void	heapify_down(t_simulation *sim, int index)
{
	int			left;
	int			right;
	int			best;
	t_request	temp;

	while (1)
	{
		left = index * 2 + 1;
		right = index * 2 + 2;
		best = index;
		if (left < sim->queue.size
			&& request_has_priority(sim, &sim->queue.requests[left],
			&sim->queue.requests[best]))
			best = left;
		if (right < sim->queue.size
			&& request_has_priority(sim, &sim->queue.requests[right],
				&sim->queue.requests[best]))
			best = right;
		if (best == index)
			break ;
		temp = sim->queue.requests[index];
		sim->queue.requests[index] = sim->queue.requests[best];
		sim->queue.requests[best] = temp;
		index = best;
	}
}
