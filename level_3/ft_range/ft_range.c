#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	len;
	int	i;
	int	*range;

	if (start <= end)
		len = end - start + 1;
	else if (start > end)
		len = start - end + 1;
	range = malloc(sizeof(int) * (len + 1));
	if (!range)
		return (NULL);
	i = 0;
	if (start <= end)
	{
		while (start <= end)
			range[i++] = start++;
	}
	else
	{
		while (start >= end)
			range[i++] = start--;
	}
	return (range);
}

int	main(void)
{
	int	start = 0;
	int	end = -3;
	int	*res;
	int	len;

	if (start <= end)
		len = end - start + 1;
	else if (start > end)
		len = start - end + 1;
	res = ft_range(start, end);
	if (!res)
		return (1);
	int	i = 0;
	while (i < len)
	{
		printf("%d %d\n", i, res[i]);
		i++;
	}
	free(res);
	return (0);
}

