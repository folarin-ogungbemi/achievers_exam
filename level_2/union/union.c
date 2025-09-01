#include <unistd.h>

int	seen(char *str, char c, int pos)
{
	int	i;

	i = 0;
	while (str[i] && (i < pos || pos == -1))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_union(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!seen(s1, s1[i], i))
			write(1, &s1[i], 1);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (!seen(s2, s2[i], i) && !seen(s1, s2[i], -1))
			write(1, &s2[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
