#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(void)
{
	int	cust_len;
	int	lib_len;

	cust_len = ft_strlen("Fantanstic 4tified");
	lib_len = strlen("Fantanstic 4tified");
	printf("%d\n", cust_len);
	printf("%d\n", lib_len);
	return (0);
}
