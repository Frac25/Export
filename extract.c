#include "export.h"

int	if_ev_name(t_nod *n)
{
	if (n->d->typ2 == evn)
	{
		return (1);
	}
	return (-1);
}

int	if_ev_value(t_nod *n)
{
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
	//printf("n_tmp->c = %s et n->nod_size = %d\n", n_tmp->c, n->nod_size);
	while (i < n->nod_size)
	{
		if (n_tmp->detail == NULL)
		{
			if (f(n_tmp) == 1)
			{
				n_last = add_nod_e(n_tmp, n_last);
//				printf(" ajout de : n_tmp->c = %s\n", n_tmp->c);
			}
		}
		else
			n_last = extract_if(n_tmp->detail, n_last, f);
		n_tmp = n_tmp->next;
		i++;
	}
	if (n->level == 0)
		close_nod(n_last);
	return (n_last);
}

char	*nod_to_txt_e(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;
	char	*c;

	if (n == NULL)
		return (NULL);
	c = NULL;
	n_tmp = n;
	i = 0;
	while (i < n->nod_size)
	{
		c = ft_strjoin2(c, n_tmp->copy->c);
		n_tmp = n_tmp->next;
		i++;
	}
	free_nod(n);
	return (c);
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
/*t_nod	*extract_if27(t_nod *n, int (*f)(t_nod*))
{
	int		i;
	t_nod	*n_tmp;
	t_nod	*n_last;

	n_tmp = n;
	n_last = NULL;
	i = 0;
	while (i < n->nod_size)
	{
		if (n_tmp->detail != NULL)
			n_last = extract_if27(n_tmp->detail, f);
		if (n_tmp->detail == NULL)
		{
			if (f(n_tmp) == 1)
				n_last = add_nod_e(n_tmp, n_last);
		}
		n_tmp = n_tmp->next;
		i++;
	}
	if (n->level == 0)
		close_nod(n_last);
	return (n_last);
}*/


/**
 * @brief recherche sur le dernier niveau
 *
 * @param n  : base de donnee
 * @param n_e : stockage du resultat
 * @return t_nod* : dernier resultat
 */
/*t_nod	*extract(t_nod *n, t_nod *n_e)
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
*/

/*
char	*nod_to_txt(t_nod *n, char *c)
{
	int		i;
	t_nod	*n_tmp;
//printf("node to txt\n\n");
	n_tmp = n->prev;
	i = 0;
	while (i < n->nod_size)
	{
		if (n_tmp->detail == NULL)
			c = ft_strjoin2(c, n_tmp->c);
		else
			c = nod_to_txt(n_tmp->detail, c);
		n_tmp = n_tmp->prev;
		i++;
	}
	return (c);
}
*/