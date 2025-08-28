#include <unistd.h>
#include <stdio.h>

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		nbr = nbr * 10;
		nbr += *str - 48;
		str++;
	}
	return (nbr * sign);
}

int	main(int ac, char **av)
{
	int	result;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	result = ft_atoi(av[1]);
	printf("%d\n", result);
	return(0);
}
