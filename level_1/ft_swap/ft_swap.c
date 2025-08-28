#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(void)
{
	int	old;
	int	new;

	old = 255;
	new = 5;
	printf("old: %d\n", old);
	printf("new: %d\n", new);
	printf("--------------\n");
	ft_swap(&old, &new);
	printf("old: %d\n", old);
	printf("new: %d\n", new);
	return (0);
}
