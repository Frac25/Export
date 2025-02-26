#include "export.h"

int	provide_nbeq(t_nod *n, int nbeq)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n->prev;
	i = 0;
	while(i < n->nod_size)
	{
		if(n_tmp->typ == equ)
			nbeq++;
		n_tmp->d->nbeq = nbeq;
		if(n_tmp->detail != NULL)
			provide_nbeq(n_tmp->detail, nbeq);
		n_tmp = n_tmp->prev;
		i++;
	}
	return(0);
}

int	provide_level(t_nod *n , int level)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n;
	i = 0;
	while(i < n->nod_size)
	{
		n_tmp->level = level;
		if(n_tmp->detail != NULL)
			provide_level(n_tmp->detail, level + 1);
		n_tmp = n_tmp->next;
		i++;
	}
	return(0);
}
