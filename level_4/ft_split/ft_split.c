#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			count++;
			while (*str && !ft_isspace(*str))
				str++;
		}
		str++;
	}
	return (count);
}

char	*copy_word(char *str, char **next)
{
	char	*word;
	char	*start;
	char	*end;
	int		i;

	while (ft_isspace(*str))
		str++;
	start = str;
	while (*str && !ft_isspace(*str))
		str++;
	end = str;
	word = (char *)malloc((end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	if (next)
		*next = str;
	return (word);
}

void	free_split(char **split, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char *str)
{
	char	**split;
	int		len;
	int		i;

	len = count_words(str);
	split = (char **)malloc(sizeof(char *) * (len + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*str && (i < len))
	{
		split[i] = copy_word(str, &str);
		if (!split[i])
			return (free_split(split, i), NULL);
		i++;
	}
	split[i] = NULL;
	return (split);
}

int	main(int ac, char **av)
{
	char	**split;
	int		i;
	int		j;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	split = ft_split(av[1]);
	if (!split)
		return (1);
	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
			write(1, &split[i][j++], 1);
		if (split[i + 1])
			write(1, "\n", 1);
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}
