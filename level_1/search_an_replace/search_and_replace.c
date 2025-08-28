#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	char	x;

	if (ac != 4 || !av[1][0] || av[2][1] || av[3][1])
	{
		write(1, "\n", 1);
		exit(EXIT_FAILURE);
	}
	while (*av[1])
	{
		if (*av[1] == *av[2])
			x = *av[3];
		else
			x = *av[1];
		write(1, &x, 1);
		av[1]++;
	}
	write(1, "\n", 1);
	exit(EXIT_SUCCESS);
}
