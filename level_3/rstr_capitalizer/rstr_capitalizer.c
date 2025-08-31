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
	int		last;
	char	c;

	i = start - 1;
	last = -1;
	while (++i < end)
		if (ft_isletter(str[i]))
			last = i;
	i = start;
	while (i < end)
	{
		c = str[i];
		if (ft_isletter(c))
		{
			if ((i != last) && (str[i] >= 65 && str[i] <= 90))
				c += 32;
			if ((i == last) && (str[i] >= 97 && str[i] <= 122))
				c -= 32;
		}
		write(1, &c, 1);
		i++;
	}
}

void	rstr_capitalizer(char *str)
{
	int	start;
	int	end;
	int	i;

	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
		{
			write(1, &str[i], 1);
			i++;
		}
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
		return (1);
	}
	i = 1;
	while (av[i] && (i < ac))
	{
		rstr_capitalizer(av[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
