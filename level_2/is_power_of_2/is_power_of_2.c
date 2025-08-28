#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	is_power_of_2_bit(unsigned int n)
{
	if (n == 0)
		return (0);
	return ((n & (n - 1)) == 0);
}

int	is_power_of_2(unsigned int n)
{
	unsigned int	i;

	i = 1;
	while (i <= n)
	{
		if (i == n)
			return (1);
		i = i * 2;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	int res1 = is_power_of_2_bit(atoi(av[1]));
	int res2 = is_power_of_2(atoi(av[1]));
	printf("bit-wise: %d\n", res1);
	printf("loop: %d\n", res2);
	return (0);
}
