#include "export.h"

t_nod	*parsing(char *c)
{
	t_nod	*n;

	n = add_nod(und, ft_strlen(c), c, ft_strlen(c), NULL); //level 0
	close_nod(n);
	check_quote(n, DQ);
	check_quote(n, SQ);
	sep_level1(n);
	sep_ll_level2(n);
	prov_al_level(n, 0);
	prov_al_nbeq(n, 0);
	prov_ll_ev(n);
	print_nod_l(n);
	read_ll_error(n);
	printf("passe\n");
	return (n);
}

char	*nod_to_txt(t_nod *n, char *c)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n->prev;
	i = 0;
	while (i < n->nod_size)
	{
		if (n_tmp->detail == NULL)
			c = ft_strjoin2(c, n_tmp->c);
		else
			c = nod_to_txt(n_tmp->detail, c);
		n_tmp = n_tmp->prev;
		i++;
	}
	return (c);
}

char	*nod_to_txt_e(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;
	char	*c;

	if (n == NULL)
		return (NULL);
	c = NULL;
	n_tmp = n;
	i = 0;
	while (i < n->nod_size)
	{
		c = ft_strjoin2(c, n_tmp->copy->c);
		n_tmp = n_tmp->next;
		i++;
	}
	return (c);
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
				printf("quote %d non fermee\n", quote);//suppr printf SDU
				exit(EXIT_FAILURE);//revoir cause free SDU
			}
		}
		i++;
	}
	return (0);
}
