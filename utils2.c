#include "export.h"
/**
 * @brief recherche la nouvelle ve saisie dans env ,
 * renvoie l indice de s2 ou s1 a ete trouve. sinon renvoie -1;
 *
 * @param s1 : Noms de ve saisi
 * @param s2 : = env
 * @return int
 */
int	arg_exist(char *s1, char **s2)
{
	int	i;
	int	l;

	l = ft_strlen(s1);
	i = 0;
	while (s2[i])
	{
		if (ft_search_cins(s2[i], '=') == l && ft_strncmp(s2[i], s1, l) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	**ft_strjoin_21(char *s1, char **s2)
{
	char	**c;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	c = malloc(sizeof(char *) * (size_2(s2) + 1));
	if (c == NULL)
		return (NULL);
	i = 0;
	while (i < size_2(s2))
	{
		c[i] = s2[i];
		i++;
	}
	c[i] = s1;
	i++;
	c[i] = NULL;
	return (c);
}
