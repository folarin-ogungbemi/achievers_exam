#include <unistd.h>

int	ft_isspace(char c)
{
	if (c == 32 || c >= 9 && c <= 13)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	char	*end;
	char	*start;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (*av[1])
		av[1]++;
	av[1]--;
	while (ft_isspace(*av[1]))
		av[1]--;
	end = av[1];
	while (*av[1] && !ft_isspace(*av[1]))
		av[1]--;
	start = av[1];
	while (++start <= end)
		write(1, start, 1);
	write(1, "\n", 1);
	return (0);
}
