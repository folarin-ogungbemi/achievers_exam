#include <unistd.h>

int	ft_islower(char c)
{
	if ((c >= 97 && c <= 122))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	char	c;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (*av[1])
	{
		while (ft_islower(*av[1]))
			write(1, av[1]++, 1);
		if (*av[1] == '_')
			av[1]++;
		if (*av[1] && ft_islower(*av[1]))
		{
			c = *av[1] - 32;
			write(1, &c, 1);
			av[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
