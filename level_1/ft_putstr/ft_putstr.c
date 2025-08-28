#include <unistd.h>

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
		write(1, str++, 1);
}

int	main(void)
{
	ft_putstr("Hello World");
	write(1, "\n", 1);
	return (0);
}
