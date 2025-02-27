#include "export.h"

int	provide_nbeq(t_nod *n, int nbeq)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n->prev;
	i = 0;
	while (i < n->nod_size)
	{
		if (n_tmp->typ == equ)
			nbeq++;
		n_tmp->d->nbeq = nbeq;
		if (n_tmp->detail != NULL)
			provide_nbeq(n_tmp->detail, nbeq);
		n_tmp = n_tmp->prev;
		i++;
	}
	return (0);
}

int	provide_level(t_nod *n, int level)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n;
	i = 0;
	while (i < n->nod_size)
	{
		n_tmp->level = level;
		if (n_tmp->detail != NULL)
			provide_level(n_tmp->detail, level + 1);
		n_tmp = n_tmp->next;
		i++;
	}
	return (0);
}

int	is_ev_ll(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n;
	i = 0;
	while (i < n->nod_size)
	{
		if (n_tmp->detail == NULL)
			is_ev(n_tmp);
		else
			is_ev_ll(n_tmp->detail);
		n_tmp = n_tmp->next;
		i++;
	}
	return (0);
}

int	is_ev(t_nod *n)
{
	if (n->d->nbeq > 1)
	{
		perror("error : plusieurs '=' ");
		exit(EXIT_FAILURE);
	}
	if (n->d->nbeq == 0 && is_evn(n->c) == 1)
	{
		n->d->typ2 = evn;
		return (0);
	}
	if (n->d->nbeq == 1 && is_evv(n->c) == 1)
	{
		n->d->typ2 = evv;
		return (0);
	}
	return (-1);
}
// ./export "\"test\"" SDU a faire, KO
