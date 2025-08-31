#include <unistd.h>

unsigned int	lcm(unsigned int x, unsigned int y)
{
	if (x == 0 || y == 0)
		return (0);




int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	unsigned int	res = lcm(atoi(av[1]), atoi(av[2]));
	printf("%d\n", res);
	return (0);
}
