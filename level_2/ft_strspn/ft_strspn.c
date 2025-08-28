#include <stdio.h>
#include <unistd.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	const char	*str;
	const char	*a;

	str = s;
	while (*s)
	{
		a = accept;
		while (*a && *a != *s)
			a++;
		if (!*a)
			return (s - str);
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
	cus = ft_strspn(av[1], av[2]);
	lib = strspn(av[1], av[2]);
	printf("%ld\n", cus);
	printf("%ld\n", lib);
	return (0);
}
