#include <unistd.h>

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_isletter(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

void	process_word(char *str, int start, int end)
{
	int		i;
	int		first;
	char	c;

	i = start;
	if (ft_isletter(str[i]))
		first = i;
	while (str[i] && (i < end))
	{
		c = str[i];
		if ((i == first) && (str[i] >= 97 && str[i] <= 122))
			c -= 32;
		if ((i != first) && (str[i] >= 65 && str[i] <= 90))
			c += 32;
		write(1, &c, 1);
		i++;
	}
}

void	str_capitalizer(char *str)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			write(1, &str[i++], 1);
		start = i;
		while (str[i] && !ft_isspace(str[i]))
			i++;
		end = i;
		if (start < end)
			process_word(str, start, end);
	}
}

int	main(int ac, char **av)
{
	int	i;

	if (ac <= 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (av[i] && (i < ac))
	{
		str_capitalizer(av[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
