#include "export.h"

int	arg_exist(char **s1, char *s2)
{
	int	i;
	int	l;

	l = ft_search_cins(s2, '=');
	i = 0;
	while(s1[i])
	{
		if (ft_search_cins(s1[i], '=') == l && ft_strncmp(s1[i], s2, l) == 0) //mot trouvé
			return(i);
		i++;
	}
	return(-1);
}

char	**ft_strjoin_21(char **s1, char *s2)
{
	char		**c;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	c = malloc(sizeof(char *) * (size_2(s1) + 2));
	if (c == NULL)
		return (NULL);
	i = 0;
	while (i < size_2(s1))
	{
		c[i] = s1[i];
		i++;
	}
	c[i] = s2;
	i++;
	c[i] = NULL;
	return (c);
}
