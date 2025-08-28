#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "do_op.h"

int	main(int ac, char **av)
{
	if (ac != 4 || !av[1] || av[2][1] || !av[3])
	{
		write(1, "\n", 1);
		exit(EXIT_FAILURE);
	}
	do_op(atoi(av[1]), av[2][0], atoi(av[3]));
	printf("\n");
	exit(EXIT_SUCCESS);
}
