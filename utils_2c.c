#include "export.h"

int	size_2(char **c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	free_2(char **c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		free(c[i]);
		i++;
	}
	free(c);
}

char	**ft_strjoin_2(char **s1, char **s2)
{
	char	**c;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	c = malloc(sizeof(char *) * (size_2(s1) + size_2(s2) + 1));
	if (c == NULL)
		return (NULL);
	i = 0;
	while (i < size_2(s1))
	{
		c[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < size_2(s2))
		c[i++] = s2[j++];
	c[i] = NULL;
	return (c);
}

char	**ft_copy_2(char **s1)
{
	char	**c;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	c = malloc(sizeof(char *) * (size_2(s1)));
	if (c == NULL)
		return (NULL);
	i = 0;
	while (i < size_2(s1))
	{
		c[i] = malloc(sizeof(char) * (ft_strlen(s1[i])));
		j = 0;
		while (j < ft_strlen(s1[i]))
		{
			c[i][j] = s1[i][j];
			j++;
		}
		c[i][j] = '\0';
		i++;
	}
	c[i] = NULL;
	return (c);
}

void	print_2c(char **c)
{
	int	i;
	int	j;

	i = 0;
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			j++;
		}
		write(1, c[i], j);
		write(1, "\n", 1);
		i++;
	}
	write(1, c[i], j);
	write(1, "\n", 1);
}
