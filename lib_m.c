#include "export.h"

/**
 * @brief idem strjoin avec fonctionnement meme si s1 ou s2 est NULL et free de s1
 *
 * @param s1
 * @param s2
 * @return char*
 */
char	*ft_strjoin2(char *s1, char *s2)
{
	char		*c;
	int		i;
	int		j;

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
//	free(s2);
	return (c);
}

int	ft_strcmp2(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	while (t1[i] && t2[i] && t1[i] == t2[i])
		i++;
	return (t1[i] - t2[i]);
}

int	cpy(char *c, char const *s1, int i)
{
	c[i] = s1[i];
	i++;
	return (i);
}

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*c;
	int	i;
	int	j;
	int		l;

	l = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	if (s1 && s2)
	{
		c = malloc(sizeof(char) * l + 1);
		if (c == NULL)
			return (NULL);
		i = 0;
		while (i < ft_strlen(s1))
			i = cpy(c, s1, i);
		j = 0;
		while (j < ft_strlen(s2))
			c[i++] = s2[j++];
		j = 0;
		while (j < ft_strlen(s3))
			c[i++] = s3[j++];
		c[i] = '\0';
		return (c);
	}
	return (NULL);
}
