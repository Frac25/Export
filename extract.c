#include "export.h"

int	if_ev_name(t_nod *n)
{
//	printf("n->d->typ2 = %d\n", n->d->typ2);
	if (n->d->typ2 == evn)
	{
		return (1);
	}
	return (-1);
}

int	if_ev_value(t_nod *n)
{
//	printf("n->d->typ2 = %d\n", n->d->typ2);
	if (n->d->typ2 == evv)
	{
		return (1);
	}
	return (-1);
}

/**
 * @brief recherche sur le dernier niveau en
 * fonction de la fonction de tri donnee
 *
 * @param n : base de donnee
 * @param n_e : stockage du resultat
 * @param f : fonction de tri
 * @return t_nod* : dernier resultat
 */
t_nod	*extract_if(t_nod *n, t_nod *n_e, int (*f)(t_nod*))
{
	int		i;
	t_nod	*n_tmp;
	t_nod	*n_last;

	n_tmp = n;
	n_last = n_e;
	i = 0;
	while (i < n->nod_size)
	{
		if (n_tmp->detail == NULL)
		{
			if (f(n_tmp) == 1)
				n_last = add_nod_e(n_tmp, n_last);
		}
		else
			n_last = extract_if(n_tmp->detail, n_last, f);
		n_tmp = n_tmp->next;
		i++;
	}
	if (n->level == 0)
		close_node(n_last);
	return (n_last);
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
	while (i < n->nod_size)
	{
		if (n_tmp->detail == NULL)
		{
			if (n->d->typ2 != evn)
				n_last = add_nod_e(n_tmp, n_last);
		}
		else
			n_last = extract(n_tmp->detail, n_last);
		n_tmp = n_tmp->next;
		i++;
	}
	return (n_last);
}
