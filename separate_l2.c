#include "export.h"

int	sep_ll_level2(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n->prev;
	i = 0;
	while (i < n->nod_size)
	{
		if (n_tmp->detail == NULL)
		{
			if (sep_level2(n_tmp) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			sep_ll_level2(n_tmp->detail);
		}
		n_tmp = n_tmp->prev;
		i++;
	}
	return (0);
}

int	sep_level2(t_nod *n)
{
	int		i;
	int		l;
	char	*c;

	c = NULL;
	i = 0;
	if (n->typ == d_q || n->typ == txt)
	{
		while (n->c[i])
		{
			i = sep_ev(n, e_v, '$', i);
			if (n->c[i] != '$')
			{
				l = 0;
				while (n->c[i] && n->c[i] != '$')
				{
					i++;
					l++;
				}
				if (l > 0)
				{
					c = ft_substr_rev(n->c, i, l);
					n->detail = add_nod(txt, c, n->detail);
				}
			}
		}
		close_nod(n->detail);
	}
	return (0);
}

int	sep_ev(t_nod *n, t_typ typ, int sep, int i)
{
	int		l;
	char	*c;

	c = NULL;
	l = 0;
	if (n->c[i] == sep)
	{
		i++;
		while (n->c[i] && is_evn_c(n->c[i]) == 1)
		{
			i++;
			l++;
		}
		if (l > 0)
		{
			c = ft_substr_rev(n->c, i, l);
			n->detail = add_nod(typ, c, n->detail);
		}
	}
	return (i);
}

