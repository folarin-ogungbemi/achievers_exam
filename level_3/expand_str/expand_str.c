#include <unistd.h>

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int	word;

	word = 0;
	if (ac != 2 || !av[1])
	{
		write(1, "\n", 1);
		return (1);
	}
	while (*av[1])
	{
		while (ft_isspace(*av[1]))
			av[1]++;
		if (*av[1] && !ft_isspace(*av[1]))
		{
			if (word)
				write(1, "   ", 3);
			while (*av[1] && !ft_isspace(*av[1]))
				write(1, av[1]++, 1);
			word = 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}
