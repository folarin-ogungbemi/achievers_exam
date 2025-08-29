#include <stdio.h>

int	ft_isspace(char c)
{
	if (c == 32 || c >= 9 && c <= 13)
		return (1);
	return (0);
}

void	clean_str(const char *str, int *sign)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	digit;
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	clean_str(str, &sign);
	while (*str)
	{
		if (*str >= 48 && *str <= 57)
			digit = *str - 48;
		else if (*str >= 97 && *str <= 102)
			digit = (*str - 97) + 10;
		else if (*str >= 65 && *str <= 70)
			digit = (*str - 65) + 10;
		else
			break ;
		if (digit >= str_base)
			break ;
		nb = nb * str_base + digit;
		str++;
	}
	return (nb * sign);
}
/*
int	main(void)
{
	printf("%d\n", ft_atoi_base("1010", 2));     // binary → 10
	printf("%d\n", ft_atoi_base("-7f", 16));     // hex → -127
	printf("%d\n", ft_atoi_base("7G", 16));
	printf("%d\n", ft_atoi_base("2A", 10));
	printf("%d\n", ft_atoi_base("123", 4));      // base 4 → 27
	printf("%d\n", ft_atoi_base("12FDB3", 16));  // hex → 1243571
	return (0);
}*/
