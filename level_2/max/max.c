#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int	i;
	int	temp;

	if (tab == 0 || len == 0)
		return (0);
	i = 0;
	temp = i;
	while (i < len)
	{
		if (tab[i] > tab[temp])
			temp = i;
		i++;
	}
	return (tab[temp]);
}

int	main(void)
{
	//int	tab[8] = {0, 2, 1, 45, 17, 5, 87, 0};
	//int	tab[4] = {5, 5, 5, 5};
	int tab[3] = {2147483647, 0, -2147483648};
	//int	tab[8] = {-3, -7, -10, -1, -9, -15, -4, 0};
	//int	tab[1] = {42};
	int	len = sizeof(tab) / sizeof(int);
	int	res = max(tab, len);
	printf("%d\n", res);
	return (0);
}
