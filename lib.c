#include "export.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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


char	*ft_strjoin2(char *s1, char *s2)
{
	char		*c;
	size_t		i;
	size_t		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	if (s1 != NULL)
		i = ft_strlen(s1);
	j = 0;
	if (s2 != NULL)
		j = ft_strlen(s2);
	c = (char *) malloc(sizeof(char) * (i + j + 1));
	if (c == NULL)
		return (NULL);
	c[i + j] = '\0';
	while (j-- > 0)
		c[i + j] = s2[j];
	while (i-- > 0)
		c[i] = s1[i];
	free(s1);
	free(s2);
	return (c);
}