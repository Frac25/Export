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
	int	n;

	i = 0;
	n = 0;
	while(c[i])
	{
		if(c[i] == 34) //double
		{
			n++;
			i++;
			while(c[i] && c[i] != 34)
				i++;
			if(!c[i])
				return(exit_quote(34));
		}
		if(c[i] == 39) //simple,
		{
			n++;
			i++;
			while(c[i] && c[i] != 39)
				i++;
			if(!c[i])
				return(exit_quote(39));
		}
		i++;
	}
	if(n > 0)
	{
		printf("toutes les quotes sont fermees\n");
		return(1);
	}
	printf("pas de quotes\n");
	return(0);
}

t_nod	*sep_quote(char *c)
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
			n = add_nod(d_q, l, c, i, n);
			sep_ve(n);
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
			n = add_nod(s_q, l, c, i, n);
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
			sep_ve(n);
		}
	}

	close_node(n);
	print_nod_l(n,0);
	printf("fin de quote!\n");
	return (n);
}

char *format_txt(char *c)
{
	int cq;
	int i;
	t_nod *n;
	char *c_new = NULL;

	cq = check_quote(c);
	if (cq == -1)
		exit(EXIT_FAILURE);
	if (cq == 0)
		return (c);
	if (cq == 1)
	{
//		printf("nod_txt = %s", nod_txt(sep_quote(c), NULL));
		c_new = nod_txt(sep_quote(c), NULL);
		return (c_new);
	}
	perror("erreur format.txt");
	exit(EXIT_FAILURE);
}

char	*nod_txt(t_nod *n, char *c)
{
	int		i;
	t_nod	*n_tmp;

//	printf("passe nod_txt\n");
	n_tmp = n->prev;
	i = 0;
	c = NULL;
//	printf("n->nod_size = %d\n", n->nod_size);
	while(i < n->nod_size)
	{
		if(n_tmp->detail == NULL)
			c = ft_strjoin2(c, n_tmp->c); // il faudra free c dans join
		else
			c = nod_txt(n_tmp->detail, NULL);
		n_tmp = n_tmp->prev;
		i++;
	}
//	printf("c3 = %s\n", c);
	return(c);
}

// ./export "\"test\""
