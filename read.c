#include "export.h"

void	read_ll_error(t_nod *n)//idem print, regrouper?
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n->prev;
	i = 0;
	while (i < n->nod_size)
	{
		if (n_tmp->detail == NULL)
			read_error(n_tmp);
		else
			read_ll_error(n_tmp->detail);
		n_tmp = n_tmp->prev;
		i++;
	}
}

void	read_error(t_nod *n)
{
	if (n->d->nbeq > 1)
	{
		perror("error : plusieurs '=' "); //SDU
		exit(EXIT_FAILURE);
	}
	if (n->typ == txt && n->d->typ2 == evn && is_evn(n->c) == -1)
	{
//		free_n0(n);
		perror("erreur de is_evn");
		exit(0);
	}
	if (n->typ == txt && n->d->typ2 == evv && is_evv(n->c) == -1)
	{
//		free_n0(n);
		perror("erreur de is_evv");
		exit(0);
	}
}
