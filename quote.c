#include "export.h"

int	exit_quote(int i)
{
	if (i == 34)
	{
		printf("quote double non fermee\n");
		exit(EXIT_FAILURE);
	}
	if (i == 39)
	{
		printf("quote simples non fermee\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	check_quote(t_nod *n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (n->c[i])
	{
		if (n->c[i] == 34) //double
		{
			j++;
			i++;
			while (n->c[i] && n->c[i] != 34)
				i++;
			if (!n->c[i])
				return (exit_quote(34));
		}
		if (n->c[i] == 39) //simple,
		{
			j++;
			i++;
			while (n->c[i] && n->c[i] != 39)
				i++;
			if (!n->c[i])
				return (exit_quote(39));
		}
		i++;
	}
	if (j > 0)
	{
		printf("toutes les quotes sont fermees\n");
		return (1);
	}
	printf("pas de quotes\n");
	return (0);
}

int	sep_quote(t_nod *n)
{
	int		i;
	int		l;

	i = 0;
	while (n->c[i])
	{
		if (n->c[i] == 34) //double
		{
			i++;
			l = 0;
			while (n->c[i] && n->c[i] != 34)
			{
				i++;
				l++;
			}
			n->detail = add_nod(d_q, l, n->c, i, n->detail);
			i++;
		}
		if (n->c[i] == 39) //simple
		{
			i++;
			l = 0;
			while (n->c[i] && n->c[i] != 39)
			{
				i++;
				l++;
			}
			n->detail = add_nod(s_q, l, n->c, i, n->detail);
			i++;
		}
		if (n->c[i] == '=') //egal
		{
			n->detail = add_nod(equ, 1, n->c, i + 1, n->detail);
			i++;
		}
		if (n->c[i] && n->c[i] != 34 && n->c[i] != 39 && n->c[i] != '=') //txt
		{
			l = 0;
			while (n->c[i] && n->c[i] != 34 && n->c[i] != 39 && n->c[i] != '=')
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
