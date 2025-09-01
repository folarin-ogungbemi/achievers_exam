#include <unistd.h>

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

void	rev_wstr(char *str)
{
	int	start;
	int	end;
	int	first;

	first = 1;
	while (str[end])
		end++;
	while (end > 0)
	{
		while (end > 0 && ft_isspace(str[end - 1]))
			end--;
		if (end == 0)
			break ;
		start = end;
		while (start > 0 && !ft_isspace(str[start - 1]))
			start--;
		if (!first)
			write(1, " ", 1);
		write(1, str + start, end - start);
		first = 0;
		end = start;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	rev_wstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
