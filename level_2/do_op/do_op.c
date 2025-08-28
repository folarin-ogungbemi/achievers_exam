#include <stdio.h>

void	do_op(int x, char c, int y)
{
	if (c == '+')
		printf("%d", x + y);
	if (c == '-')
		printf("%d", x - y);
	if (c == '*')
		printf("%d", x * y);
	if (c == '/')
		printf("%d", x / y);
}
