#include "export.h"

/**
 * @brief recherche la premiere position d'un caractere dans une chaine
 *
 * @param s
 * @param c
 * @return int
 * @result si pas trouve ou si c ou s est nul : -1, sinon : position de c dans s
 */
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
