#include "export.h"

int	sep_quote(t_nod *n, t_typ typ, int sep, int i)
{
	int	l;

	if (n->c[i] == sep)
	{
		i++;
		l = 0;
		while (n->c[i] && n->c[i] != sep)
		{
			i++;
			l++;
		}
		n->detail = add_nod(typ, l, n->c, i, n->detail);
		i++;
	}
	return(i);
}

int	sep_char(t_nod *n, t_typ typ, int sep, int i)
{
	if (n->c[i] == sep)
		{
			n->detail = add_nod(typ, 1, n->c, i + 1, n->detail);
			i++;
		}
	return(i);
}

int	sep_level1(t_nod *n) //SDU racourcir et deplacer
{
	int		i;
	int		l;

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
			n->detail = add_nod(txt, l, n->c, i, n->detail);
		}
	}
	close_nod(n->detail);
	return (0);
}

int	sep_ll_level2(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n;
	i = 0;
	while (i < n->nod_size)
	{
//		printf("c = %s\n", n->c);
		if (n_tmp->detail == NULL)
		{
//			printf("passe1\n");
			if(sep_level2(n_tmp) == -1)//
				exit(EXIT_FAILURE);
		}
		else
		{
//			printf("passe2\n");
			sep_ll_level2(n_tmp->detail);
		}
		n_tmp = n_tmp->next;
		i++;
	}
	return (0);
}

int	sep_level2(t_nod *n)
{
	int		i;
	int		l;
	//nd

	i = 0;
	if (n->typ == d_q || n->typ == txt)
	{
		while (n->c[i])
		{
			i = sep_ev(n, e_v, '$', i);
			if(n->c[i] != '$')
			{
				l = 0;
				while (n->c[i] && n->c[i] != '$')
				{
					i++;
					l++;
				}
				if (l > 0)
					n->detail = add_nod(txt, l, n->c, i, n->detail);
			}
//			i++; //SDU2
		}
		close_nod(n->detail);//
	}
	return (0);
}

int	sep_ev(t_nod *n, t_typ typ, int sep, int i)
{
	int	l;

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
			n->detail = add_nod(typ, l, n->c, i, n->detail);
	}
	return (i);
}
