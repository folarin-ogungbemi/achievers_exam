#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	min;
	int		temp;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[min])
				min = j;
			j++;
		}
		if (i != min)
		{
			temp = tab[i];
			tab[i] = tab[min];
			tab[min] = temp;
		}
		i++;
	}
}

void	sort_int_tab_swap(int *tab, unsigned int size)
{
	int	swapped;
	int	i;
	int	temp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

int	main(void)
{
	int	tab[8] = {0, 4, 2, 17, 5, 89, 1, 0};
	unsigned int	size;

	size = sizeof(tab)/sizeof(tab[0]);
	sort_int_tab(tab, size);
	//sort_int_tab_swap(tab, size);
	int	i = 0;
	while (i < size)
	{
		printf("%d: %d\n", i, tab[i]);
		i++;
	}
	return (0);
}
