#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

char	*ft_strcpy(char *s1, const char *s2)
{
	size_t	i;

	if (!s2)
		return (NULL);
	i = 0;
	while (s2[i])
	{	
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	main(void)
{
	char	buffer[BUFFER_SIZE];
	
	char *res = ft_strcpy(buffer, NULL);
	printf("result: %s\n", res);
	printf("dest: %s\n", buffer);
	return (0);
}


