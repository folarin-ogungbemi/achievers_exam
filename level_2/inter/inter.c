#include <unistd.h>
#include <stdio.h>

int	seen(char *str, char c, char *s)
{
	int	i;

	i = 0;
	while (*str && i < (s - str))
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	inter(char *s1, char *s2)
{
	char	*str1;
	char	*str2;

	str1 = s1;
	while (*s1)
	{
		if (!seen(str1, *s1, s1))
		{
			str2 = s2;
			while (*str2)
			{
				if (*str2 == *s1)
				{
					write(1, s1, 1);
					break;
				}
				str2++;
			}
		}
		s1++;
	}
}	

int	main(int ac, char **av)
{
	if (ac != 3 || !av[1] || !av[2])
	{
		write(1, "\n", 1);
		return (1);
	}
	inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
