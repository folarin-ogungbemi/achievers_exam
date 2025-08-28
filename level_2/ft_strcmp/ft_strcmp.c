#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	main(int ac, char **av)
{
	int	cus;
	int	lib;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	cus = ft_strcmp(av[1], av[2]);
	lib = strcmp(av[1], av[2]);
	printf("%d\n", cus);
	printf("%d\n", lib);
	return(0);
}
