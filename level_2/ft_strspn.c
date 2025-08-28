#include <string.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	const char	*str;
	const char	*a;

	str = s;
	while (*s)
	{
		a = accept;
		while (*a && !(*a == *s))
			a++;
		if (!*a)
			return (s - str);
		s++;
	}
	return (s - str);
}

int	main(int ac, char **av)
{
	size_t	res1;
	size_t	res2;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	res1 = ft_strspn(av[1], av[2]);
	res2 = strspn(av[1], av[2]);
	printf("%zu\n", res1);
	printf("%zu\n", res2);
	return (0);
}
