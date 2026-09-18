#include "codexion.h"

void	coder_compile(t_coder *coder)
{
	printf("coder %d compliling\n", coder->id);
	usleep(coder->sim->args.time_to_compile * 1000);
}

void	coder_debug(t_coder *coder)
{
	printf("coder %d debugging\n", coder->id);
	usleep(coder->sim->args.time_to_debug * 1000);
}

void	coder_refactor(t_coder *coder)
{
	printf("coder %d refactoring\n", coder->id);
	usleep(coder->sim->args.time_to_compile * 1000);
}
