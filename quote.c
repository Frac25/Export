#include "export.h"

int	exit_quote(int i)
{
	if(i == 34)
	{
		printf("quote double non fermee\n");
		return(-1);
	}
	if(i == 39)
	{
		printf("quote simples non fermee\n");
		return(-1);
	}
	return(0);
}

int	check_quote(char *c)
{
	int	i;

	i = 0;
	while(c[i])
	{
		if(c[i] == 34) //double
		{
			i++;
			while(c[i] && c[i] != 34)
				i++;
			if(!c[i])
				return(exit_quote(34));
		}
		if(c[i] == 39) //simple,
		{
			i++;
			while(c[i] && c[i] != 39)
				i++;
			if(!c[i])
				return(exit_quote(39));
		}
		i++;
	}
	printf("toutes les quotes sont fermees\n");
	sep_quote(c);
	return(0);
}

int	sep_quote(char *c)
{
	int		i;
	int		l;
	t_nod	*n;

	n = NULL;
	i = 0;
	while(c[i])
	{
		if(c[i] == 34) //double
		{
			i++;
			l = 0;
			while(c[i] && c[i] != 34)
			{
				i++;
				l++;
			}
			n = add_nod(d_quote, l, c, i, n);
			var_env(n);
			i++;
		}
		if(c[i] == 39) //simple
		{
			i++;
			l = 0;
			while(c[i] && c[i] != 39)
			{
				i++;
				l++;
			}
			n = add_nod(txt, l, c, i, n);
			i++;
		}
		if(c[i] && c[i] != 34 && c[i] != 39) //txt
		{
			l = 0;
			while(c[i] && c[i] != 34 && c[i] != 39)
			{
				i++;
				l++;
			}
			n = add_nod(txt, l, c, i, n);
		}
	}
	print_nod(n);
	return(0);
}

void	init_nod(t_nod *n)
{
	n->index = 0;
	n->level = 0;
}

t_nod	*add_nod(t_typ typ, int l, char *c, int i, t_nod *last_nod)
{
	t_nod	*n;
	int		j;

	n = malloc(sizeof(t_nod));
	if (last_nod == NULL)
		init_nod(n);
	n->index++;
	n->size = l;
	n->typ = typ;
	n->next = last_nod;
	n->c = malloc(sizeof(char) * n->size + 1);
	n->c[n->size] = '\0';
	j = 1;
	while(j <= n->size)
	{
		n->c[n->size - j] = c[i - j];
		j++;
	}
	return(n);
}

void	print_nod(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n;
	i = 0;
	while(n_tmp)
	{
		printf("%s\n", n_tmp->c);
		n_tmp = n_tmp->next;
	}
}
