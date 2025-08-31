#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	gcd(unsigned int a, unsigned int b)
{
	int	temp;

	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	return ((a / gcd(a, b)) * b);
}

int	main(int ac, char **av)
{
	int	res;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	res = lcm(atoi(av[1]), atoi(av[2]));
	printf("%d\n", res);
	return (0);
}
