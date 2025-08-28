#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	count;
	char	*str;

	count = 0;
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = av[1];
	while (*av[1])
	{
		while (*av[2])
		{
			if (*av[1] == *av[2])
			{
				count++;
				break ;
			}
			av[2]++;
		}
		av[1]++;
	}
	if (ft_strlen(str) == count)
		write(1, str, count);
	write(1, "\n", 1);
	return (0);
}	
