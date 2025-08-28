#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (*av[1])
	{
		if (*av[1] >= 65 && *av[1] <= 90)
		{
			i = 0;
			while (i++ < ((*av[1] - 65) + 1))
				write(1, av[1], 1);
			av[1]++;
		}
		if (*av[1] >= 97 && *av[1] <= 122)
		{
			i = 0;
			while (i++ < ((*av[1] - 97) + 1))
				write(1, av[1], 1);
			av[1]++;
		}
		else
			write(1, av[1]++, 1);
	}
	write(1, "\n", 1);
	return (0);
}
