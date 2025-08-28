#include <unistd.h>

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (ft_isspace(*av[1]))
		av[1]++;
	while (*av[1] && !ft_isspace(*av[1]))
		write(1, av[1]++, 1);
	write(1, "\n", 1);
	return (0);
}
