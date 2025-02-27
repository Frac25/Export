#include "export.h"



int	if_name(t_nod *n)
{
//	printf("n->d->typ2 = %d\n", n->d->typ2);
	if (n->d->typ2 == evn)
	{
		return (1);
	}
	return(-1);
}

int	if_value(t_nod *n)
{
//	printf("n->d->typ2 = %d\n", n->d->typ2);
	if (n->d->typ2 == evv)
	{
		return (1);
	}
	return(-1);
}

t_nod	*extract_if(t_nod *n, t_nod *n_e, int (*f)(t_nod*))
{
	int		i;
	t_nod	*n_tmp;
	t_nod	*n_last;

	n_tmp = n;
	n_last = n_e;
	i = 0;

	while(i < n->nod_size)
	{
		if(n_tmp->detail == NULL)
		{
			if(f(n_tmp) == 1)
			{
//				printf("f(n_tmp) = %d\n", f(n_tmp));
				n_last = add_nod_e(n_tmp, n_last);
			}
		}
		else
			n_last = extract_if(n_tmp->detail, n_last, f);
		n_tmp = n_tmp->next;
		i++;
	}
	return(n_last);
}






/**
 * @brief recherche sur le dernier niveau
 *
 * @param n  : base de donnee
 * @param n_e : stockage du resultat
 * @return t_nod* : dernier resultat
 */

t_nod	*extract(t_nod *n, t_nod *n_e)
{
	int		i;
	t_nod	*n_tmp;
	t_nod	*n_last;

	n_tmp = n;
	n_last = n_e;
	i = 0;
//	printf("n->nod_size = %d\n", n->nod_size);
	while(i < n->nod_size)
	{
		if(n_tmp->detail == NULL)
		{
			if(n->d->typ2 != evn)
				n_last = add_nod_e(n_tmp, n_last);
		}
		else
			n_last = extract(n_tmp->detail, n_last);
		n_tmp = n_tmp->next;
		i++;
	}
//	printf("c3 \n");
	return(n_last);
}
