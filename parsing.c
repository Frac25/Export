#include "export.h"

t_nod	*parsing(char *c)
{
	t_nod	*n;
	char	*c_cpy;

	c_cpy = ft_substr_rev(c, ft_strlen(c), ft_strlen(c));
	n = add_nod(und, c_cpy, NULL);
	close_nod(n);
	check_quote(n, DQ);
	check_quote(n, SQ);
	sep_level1(n);
	sep_ll_level2(n);
	prov_al_level(n, 0);
	prov_al_nbeq(n, 0);
	prov_ll_typ2(n);
	read_ll_error(n);
	return (n);
}

int	check_quote(t_nod *n, int quote)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (n->c[i])
	{
		if (n->c[i] == quote)
		{
			j++;
			i++;
			while (n->c[i] && n->c[i] != quote)
				i++;
			if (!n->c[i])
			{
				perror("quote non fermee\n");
				free_nod(n);
				exit(EXIT_FAILURE);//revoir cause free SDU
			}
		}
		i++;
	}
	return (0);
}
