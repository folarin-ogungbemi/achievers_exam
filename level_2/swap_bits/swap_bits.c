#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4) | (octet << 4);
}

int	main(void)
{
	int	i;
	unsigned char	octet;
	unsigned char	bit;

	octet = 5;
	i = 7;
	while (i >= 0)
	{
		bit = ((octet >> i) & 1) + 48;
		write(1, &bit, 1);
		i--;
	}
	write(1, "\n", 1);
	unsigned char	res = swap_bits(octet);
	i = 7;
	while (i >= 0)
	{
		bit = ((res >> i) & 1) + 48;
		write(1, &bit, 1);
		i--;
	}
	write(1, "\n", 1);
	return (0);
}
