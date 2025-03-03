#include "export.h"

int	prov_al_nbeq(t_nod *n, int nbeq)
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
			prov_al_nbeq(n_tmp->detail, nbeq);
		n_tmp = n_tmp->prev;
		i++;
	}
	return (0);
}

int	prov_al_level(t_nod *n, int level)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n;
	i = 0;
	while (i < n->nod_size)
	{
		n_tmp->level = level;
		if (n_tmp->detail != NULL)
			prov_al_level(n_tmp->detail, level + 1);
		n_tmp = n_tmp->next;
		i++;
	}
	return (0);
}


int	prov_ll_typ2(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n;
	i = 0;
	while (i < n->nod_size)
	{
		if (n_tmp->detail == NULL)
			prov_typ2(n_tmp);
		else
			prov_ll_typ2(n_tmp->detail);
		n_tmp = n_tmp->next;
		i++;
	}
	return (0);
}

int	prov_typ2(t_nod *n)
{
	if	(n->typ == equ)
		n->d->typ2 = equ;
	else if (n->d->nbeq == 0)
		n->d->typ2 = evn;
	else if (n->d->nbeq == 1)
		n->d->typ2 = evv;
	return (0);
}



/*int	prov_ll_errnum(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n;
	i = 0;
	while (i < n->nod_size)
	{
		if (n_tmp->detail != NULL)
			prov_ll_errnum(n_tmp->detail);
		else
		{
			if(n_tmp->typ == e_v)
				n_tmp->d->.. = ..;
		}
		n_tmp = n_tmp->next;
		i++;
	}
	return (0);
}
*/
