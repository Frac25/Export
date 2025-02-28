#include "export.h"

t_nod	*parsing(char *c)
{
	t_nod	*n;

	n = add_nod(und, ft_strlen(c), c, ft_strlen(c), NULL); //level 0
	close_nod(n);
	check_quote(n);
	sep_quote(n); //level 1
	sep_ev_ll(n); //level 2
	provide_level(n, 0);
	provide_nbeq(n, 0);
	is_ev_ll(n);
	print_nod_l(n);
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
			c = ft_strjoin2(c, n_tmp->c); // il faudrait free c dans join SDU
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
		c = ft_strjoin2(c, n_tmp->copy->c); // il faudrai free c dans join SDU
		n_tmp = n_tmp->next;
		i++;
	}
	return (c);
}
