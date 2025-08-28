#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i;
	unsigned char	c;

	i = 7;
	while (i >= 0)
	{
		c = ((octet >> i) & 1) + 48;
		write(1, &c, 1);
		i--;
	}
}

int	main(void)
{
	print_bits(4);
	write(1, "\n", 1);
	return (0);
}
