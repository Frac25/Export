#include "export.h"

/**
 * @brief idem strjoin avec fonctionnement meme si s1 ou s2 est NULL
 *
 * @param s1
 * @param s2
 * @return char*
 */
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
