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
	if(n->d->errnum == -1)
	{
//		free_n0(n);
		perror("erreur de is_ev");

		exit(0);
	}
}
