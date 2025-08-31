#include <unistd.h>

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	nb;
	int	sign;

	nb = 0;
	while (ft_isspace(*str))
		str++;
	while (*str && (*str >= 48 && *str <= 57))
	{
		nb = nb * 10 + *str - 48;
		str++;
	}
	return (nb);
}

int	ft_putnbr(int nb)
{
	char	c;

	if (nb > 9)
		ft_putnbr(nb / 10);
	c = nb % 10 + 48;
	write(1, &c, 1);
}

void	tab_mult(unsigned int nb)
{
	unsigned int	i;
	unsigned int	res;

	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(nb);
		write(1, " = ", 3);
		res = i * nb;
		ft_putnbr(res);
		if (i < 9)
			write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	tab_mult(ft_atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}
