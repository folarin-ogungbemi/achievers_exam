#include <stdio.h>
#include <unistd.h>

char	*ft_strrev(char *str)
{
	int	i;
	int	len;
	char	temp;

	len = 0;
	while (str[len])
		len++;
	len--;
	i = 0;
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	return (str);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	char *strrev = ft_strrev(av[1]);
	printf("%s\n", strrev);
	return (0);
}
