# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

int	size_2(char **c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	**ft_copy_2(char **s1)
{
	char	**c;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
//	printf("size_2(s1) = %d\n", size_2(s1));
//	print_2c(s1);
	c = malloc(sizeof(char *) * (size_2(s1) + 1));
	if (c == NULL)
		return (NULL);
	i = 0;
	while (i < size_2(s1))
	{
		c[i] = malloc(sizeof(char) * (ft_strlen(s1[i]) + 1));
		j = 0;
		while (j <= ft_strlen(s1[i]))
		{
			c[i][j] = s1[i][j];
			j++;
		}
		i++;
	}
	c[i] = NULL;
	return (c);
}

void	print_2c(char **c) //pb malloc
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
//	write(1, c[i], j);
	write(1, "\n", 1);
}

int main(int argc, char **argv, char **env)
{
    char **env2;

    env2 = ft_copy_2(env);
    printf("test\n");
    print_2c(env2);
    free_2(env2);
    return(0);
}

