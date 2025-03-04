#include "export.h"

int	sep_quote(t_nod *n, t_typ typ, int sep, int i)
{
	int		l;
	char	*c;

	c = NULL;
	if (n->c[i] == sep)
	{
		i++;
		l = 0;
		while (n->c[i] && n->c[i] != sep)
		{
			i++;
			l++;
		}
		c = ft_substr_rev(n->c, i, l);
		n->detail = add_nod(typ, c, n->detail);
		i++;
	}
	return (i);
}

int	sep_char(t_nod *n, t_typ typ, int sep, int i)
{
	char	*c;

	c = NULL;
	if (n->c[i] == sep)
	{
		i++;
		c = ft_substr_rev(n->c, i, 1);
		n->detail = add_nod(typ, c, n->detail);
	}
	return (i);
}

int	sep_level1(t_nod *n)
{
	int		i;
	int		l;
	char	*c;

	c = NULL;
	i = 0;
	while (n->c[i])
	{
		i = sep_quote(n, d_q, DQ, i);
		i = sep_quote(n, s_q, SQ, i);
		i = sep_char(n, equ, '=', i);
		if (n->c[i] && n->c[i] != DQ && n->c[i] != SQ && n->c[i] != '=') //SDU a ameliorer
		{
			l = 0;
			while (n->c[i] && n->c[i] != DQ && n->c[i] != SQ && n->c[i] != '=')
			{
				i++;
				l++;
			}
			c = ft_substr_rev(n->c, i, l);
			n->detail = add_nod(txt, c, n->detail);
		}
	}
	close_nod(n->detail);
	return (0);
}
