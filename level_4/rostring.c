#include <unistd.h>

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	copy_word(char **str, char **start, char **end)
{
	while (ft_isspace(**str))
		(*str)++;
	*start = *str;
	while (**str && !ft_isspace(**str))
		(*str)++;
	*end = *str;
}	

void	rostring(char *str)
{
	char	*start;
	char	*end;
	int		word;

	word = 0;
	copy_word(&str, &start, &end);
	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			if (word)
				write(1, " ", 1);
			while (*str && !ft_isspace(*str))
				write(1, str++, 1);
			word = 1;
		}
	}
	if (word)
		write(1, " ", 1);
	while (start < end)
		write(1, start++, 1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}
