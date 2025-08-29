#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	nb;

	nb = 0;
	sign = 1;
	while (*str == 32 || *str == 9 || *str == 13)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= 48 && *str <= 57))
	{
		nb = nb * 10 + (*str - 48);
		str++;
	}
	return (nb * sign);
}

void	ft_putnbr(unsigned int nb)
{
	char	c;

	if (nb > 9)
		ft_putnbr(nb / 10);
	c = nb % 10 + 48;
	write(1, &c, 1);
}

int	is_prime(unsigned int nb)
{
	int	i;

	i = 3;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	add_prime_sum(int nb)
{
	int	i;
	int	res;

	i = 1;
	res = 0;
	while (i <= nb)
	{
		if (is_prime(i))
			res += i;
		i++;
	}
	return (res);
}

int	main(int ac, char **av)
{
	int	res;

	if (ac != 2)
	{
		write(1, "0\n", 2);
		exit (EXIT_SUCCESS);
	}
	res = add_prime_sum(ft_atoi(av[1]));
	ft_putnbr(res);
	write(1, "\n", 1);
	return (0);
}
