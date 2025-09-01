#include <unistd.h>
#include <stdlib.h>

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
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
	}
	return (count);
}

char	*copy_word(char *str, char **next)
{
	char	*start;
	char	*end;
	char	*word;
	int		i;

	while (ft_isspace(*str))
		str++;
	start = str;
	while (*str && !ft_isspace(*str))
		str++;
	end = str;
	word = (char *)malloc((end - start + 1) * sizeof(char));
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

char	**rev_wstr(char *str)
{
	char	**rev;
	int		len;
	int		i;

	len = count_words(str);
	rev = (char **)malloc((len + 1) * sizeof(char *));
	if (!rev)
		return (NULL);
	i = len - 1;
	while (*str && i >= 0)
	{
		rev[i] = copy_word(str, &str);
		if (!rev[i])
		{
			while (++i < len)
				free(rev[i]);
			free(rev);
			return (NULL);
		}
		i--;
	}
	rev[len] = NULL;
	return (rev);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	**str;

	if (ac == 2)
	{
		str = rev_wstr(av[1]);
		if (!str)
			return (1);
		i = 0;
		while (str[i])
		{
			j = 0;
			while (str[i][j])
				write(1, &str[i][j++], 1);
			if (str[i + 1])
				write(1, " ", 1);
			free(str[i]);
			i++;
		}
		free(str);
	}
	write(1, "\n", 1);
	return (0);
}
