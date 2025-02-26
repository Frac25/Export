#include "export.h"

char	*format_txt(char *c)
{
	t_nod *n;
	t_nod *name;
	t_nod *value;

	int i;

	n = add_nod(und, ft_strlen(c), c, ft_strlen(c), NULL);
	close_node(n);
	check_quote(n);
	sep_quote(n);
	sep_ev_ll(n);
	replace_ev_ll(n);
	provide_level(n, 0);
	provide_nbeq(n, 0);
	is_ev_ll(n);
	print_nod_l(n);
//exit(0);
	name = extract_if(n, NULL, if_name);
//	name = extract(n, NULL);
	close_node(name);
	printf("\n");
	print_nod_e(name);
	exit(EXIT_SUCCESS);
//	printf("nod_to_txt = %s", nod_to_txt(sep_quote(c), NULL));
	return (nod_to_txt(n, NULL));
}

char	*nod_to_txt(t_nod *n, char *c)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n->prev;
	i = 0;
//	printf("n->nod_size = %d\n", n->nod_size);
	while(i < n->nod_size)
	{
		if(n_tmp->detail == NULL)
			c = ft_strjoin2(c, n_tmp->c); // il faudra free c dans join
		else
			c = nod_to_txt(n_tmp->detail, c);
		n_tmp = n_tmp->prev;
		i++;
	}
//	printf("c3 = %s\n", c);
	return(c);
}



int	is_ev_ll(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n;
	i = 0;
	while(i < n->nod_size)
	{
		if(n_tmp->detail == NULL)
		{
			if(is_ev(n_tmp) == -1)
				return (-1);
		}
		else
		{
			if(is_ev_ll(n_tmp->detail) == -1)
				return (-1);
		}
		n_tmp = n_tmp->next;
		i++;
	}
	return(0);
}

int	is_ev(t_nod *n)
{
	if(n->d->nbeq > 1)
	{
		perror("error : plusieurs '=' ");
		exit(EXIT_FAILURE);
	}
	if(n->d->nbeq == 0 && is_evn(n->c) == 1)
	{
		n->d->typ2 = evn;
		return(0);
	}
	if(n->d->nbeq == 1 && is_evv(n->c) == 1)
	{
		n->d->typ2 = evv;
		return(0);
	}
	return (-1);
}
// ./export "\"test\""

