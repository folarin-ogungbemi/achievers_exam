#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	pgcd(unsigned int x, unsigned int y)
{
	int	temp;

	while (y != 0)
	{
		temp = y;
		y = x % y;
		x = temp;
	}
	return (x);
}

int	main(int ac, char **av)
{
	int	res;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	res = pgcd(atoi(av[1]), atoi(av[2]));
	printf("%d\n", res);
	return (0);
}
