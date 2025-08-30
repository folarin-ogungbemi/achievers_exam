#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (*av[1] && *av[2])
	{
		if (*av[1] == *av[2])
			av[1]++;
		av[2]++;
	}
	if (!*av[1])
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);
	return (0);
}
