#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strdup(char *str)
{
	int	i;
	char	*dup;

	i = 0;
	while (str[i])
		i++;
	dup = (char *)malloc(i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	char	*dup = ft_strdup(av[1]);
	if (!dup)
		exit(EXIT_FAILURE);
	while (dup[i])
		write(1, &dup[i++], 1);
	write(1, "\n", 1);
	free(dup);
	return (0);
}
