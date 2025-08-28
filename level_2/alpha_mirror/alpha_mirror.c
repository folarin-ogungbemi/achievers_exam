#include <unistd.h>

int	 main(int ac, char **av)
{
	char	x;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (*av[1])
	{
		if (*av[1] >= 65 && *av[1] <= 90)
			x = 65 + (65 - *av[1]) + 25;
		else if (*av[1] >= 97 && *av[1] <= 122)
			x = 97 + (97 - *av[1]) + 25;
		else
			x = *av[1];
		write(1, &x, 1);
		av[1]++;
	}
	write(1, "\n", 1);
	return (0);
}
