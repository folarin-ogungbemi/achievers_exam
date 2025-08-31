#include <unistd.h>
#include <stdio.h>

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	nb;

	sign = 1;
	nb = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= 48 && *str <= 57))
	{
		nb = nb * 10 + *str - 48;
		str++;
	}
	return (nb * sign);
}

void	print_hex(unsigned int nb)
{
	char	c;
	char	*base;

	base = "0123456789abcdef";
	if (nb > 15)
		print_hex(nb / 16);
	c = base[nb % 16];
	write(1, &c, 1);
}


int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	print_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}
