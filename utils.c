#include "export.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_isalphanum1(char *c)
{
	int	i;
	int	ok;

	i = 0;
	if (c[0] >= '0' && c[0] <= '9')
		return(0);
	while(c[i])
	{
		ok = 0;
		if (c[i] >= 'A' && c[i] <= 'Z')
			ok++;
		else if (c[i] >= 'a' && c[i] <= 'z')
			ok++;
		else if (c[i] >= '0' && c[i] <= '9')
			ok++;
		else if (c[i] == '_')
			ok++;
		if(ok == 0)
			return(0);
		i++;
	}
	return (1);
}

int	ft_isalphanum_c(char c)
{
	if (c >= 'A' && c <= 'Z')
		return(1);
	else if (c >= 'a' && c <= 'z')
		return(1);
	else if (c >= '0' && c <= '9')
		return(1);
	else if (c == '_')
		return(1);
	return (0);
}

int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return(1);
	return (0);
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

int	size_2(char **c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return(i);
}

char	**ft_strjoin_2(char **s1, char **s2)
{
	char		**c;
	int		i;
	int	j;

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




char	*ft_strnstr(const char *str, const char *s, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str1;

	str1 = (char *)str;
	if (s[0] == '\0' )
		return (&str1[0]);
	i = 0;
	while (str1[i] && (i < len))
	{
		j = 0;
		while (str1[i + j] == s[j] && (i + j) < len && str[i + j] && s[j])
		{
			if (s[j + 1] == '\0')
				return (&str1[i]);
			j++;
		}
		i++;
	}
	return (0);
}


int	ft_search_cins(char *s, char c)
{
	int	i;

	if(s[0] == '\0' || c == '\0')
		return(-1);
	i = 0;
	while (s[i])
	{
		if(s[i] == c)
			return(i);
		i++;
	}
	return (-1);
}


int	ft_nb_char(char *s, char c)
{
	int	i;
	int	nb;

	if(s[0] == '\0' || c == '\0')
		return(-1);
	nb = 0;
	i = 0;
	while (s[i])
	{
		if(s[i] == c)
			nb++;
		i++;
	}
	return (nb);
}

int	ft_nb_str(char *s, char *c)
{
	int	i;
	int	nb;

	if(s[0] == '\0' || c[0] == '\0')
		return(-1);
	nb = 0;
	i = 0;
	while (s[i])
	{
		if(s[i] == c[0])
			nb++;
		i++;
	}
	return (nb);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*c;
	size_t		i;
	size_t		j;

	if (s1 && s2)
	{
		c = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (c == NULL)
			return (NULL);
		i = 0;
		while (i < ft_strlen(s1))
		{
			c[i] = s1[i];
			i++;
		}
		j = 0;
		while (j < ft_strlen(s2))
			c[i++] = s2[j++];
		c[i] = '\0';
		return (c);
	}
	return (NULL);
}
