#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	bit;
	int	i;

	bit = 0;
	i = 7;
	while (i >= 0)
	{
		bit = (bit << 1) | (octet & 1);
		octet = (octet >> 1);
		i--;
	}
	return (bit);
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
	unsigned char	res = reverse_bits(octet);
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
