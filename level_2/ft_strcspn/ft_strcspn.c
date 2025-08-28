#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	const char	*str;
	const char	*r;

	str = s;
	while (*s)
	{
		r = reject;
		while (*r)
		{
			if (*r == *s)
				return (s - str);
			r++;
		}
		s++;
	}
	return (s - str);
}

int	main(int ac, char **av)
{
	size_t	cus;
	size_t	lib;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	cus = ft_strcspn(av[1], av[2]);
	lib = strcspn(av[1], av[2]);
	printf("%ld\n", cus);
	printf("%ld\n", lib);
	return (0);
}
