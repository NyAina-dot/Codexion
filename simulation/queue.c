#include "codexion.h"

int	is_request_first(t_simulation *sim, t_coder *coder)
{
	return (sim->queue.size > 0
		&& sim->queue.requests[0].coder == coder);
}

int	wait_for_turn(t_coder *coder)
{
	t_simulation	*sim;

	sim = coder->sim;
	pthread_mutex_lock(&sim->queue.mutex);
	while (!is_request_first(sim, coder) && !sim->stop)
		pthread_cond_wait(&sim->queue.cond, &sim->queue.mutex);
	pthread_mutex_unlock(&sim->queue.mutex);
	return (0);
}

int	request_dongles(t_coder *coder)
{
	t_request	request;

	request.coder = coder;
	request.request_time = get_time_ms();
	request.deadline = coder->last_compile_time
		+ coder->sim->args.time_to_burnout;
	if (queue_push(coder->sim, request) != 0)
		return (1);
	return (wait_for_turn(coder));
}
