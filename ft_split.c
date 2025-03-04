#include "export.h"

int	check_free_all(char **s, int size)
{
	if (s[size] == NULL)
	{
		while (size > 0)
			free(s[--size]);
		free (s);
		return (0);
	}
	return (1);
}

void	*ft_malcol(const char *s, char c)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	p = malloc(sizeof(char *) * (j + 1));
	if (p == NULL)
		return (NULL);
	return (p);
}

void	*ft_mallin(const char *s, int end)
{
	int		i;
	char	*p;

	i = 0;
	p = malloc(sizeof(char) * (end + 1));
	if (p == NULL)
		return (NULL);
	while (i < end)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	tab = ft_malcol(s, c);
	if (tab == NULL)
		return (NULL);
	j = 0;
	while (*s != 0)
	{
		while (*s == c)
			s++;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (i > 0)
			tab[j] = ft_mallin(s, i);
		if (i > 0)
			if (check_free_all(tab, j++) == 0)
				return (NULL);
		s = s + i;
	}
	tab[j] = NULL;
	return (tab);
}
