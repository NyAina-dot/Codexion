#include <stdio.h>


int main(int ac, char **av)
{
	if (ac != 8)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}

	int i;
	i = 0;
	// while()
	av[1] = "d";
	printf("Hello");
	return (0);
}
