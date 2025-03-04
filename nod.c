#include "export.h"

void	init_nod(t_nod *n)
{
	n->next = NULL;
	n->prev = NULL;
	n->detail = NULL;
	n->copy = NULL;
	n->nod_size = 0;
	n->level = 0;
	n->typ = und;
	n->c = NULL;
	n->d = malloc(sizeof(t_data));
	n->d->typ2 = und;
	n->d->nbeq = 0;
	n->d->errnum = 0;
}

int	close_nod(t_nod *n)
{
	t_nod	*n_tmp;
	t_nod	*n_tmp2;
	int		i;

	i = 1;
	n_tmp = n;
	n_tmp2 = n;
	if (n == NULL)
		return (0);
	while (n_tmp->next != NULL)
	{
		n_tmp = n_tmp->next;
		n_tmp->prev = n_tmp2;
		n_tmp2 = n_tmp;
		i++;
	}
	n_tmp->next = n;
	n_tmp->next->prev = n_tmp;
	n->nod_size = i;
	return (0);
}

/**
 * @brief crer un nod d'une liste chainee
 *
 * @param typ : type de contenu de la chaine de caractere c
 * @param c : token a enregistrer
 * @param last_nod : nod precedant, a chainer
 * @return t_nod*
 */
t_nod	*add_nod(t_typ typ, char *c, t_nod *last_nod)
{
	t_nod	*n;

	n = malloc(sizeof(t_nod));
	init_nod(n);
	n->typ = typ;
	n->next = last_nod;
	n->c = c;
	return (n);
}

void	free_nod(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;
	t_nod	*n_s;
	int		n_size;

	n_size = n->nod_size;
	n_tmp = n;
	i = 0;
	while (i < n_size)
	{
		if (n_tmp->detail != NULL)
			free_nod(n_tmp->detail);
		n_s = n_tmp;
		n_tmp = n_tmp->next;
		free(n_s->c);
		free(n_s->d);
		free(n_s);
		n_s = NULL;
		i++;
	}
}

/**
 * @brief ajoute un nod d extraction
 *
 * @param copy_nod
 * @param last_nod
 * @return t_nod*
 */
t_nod	*add_nod_e(t_nod *copy_nod, t_nod *last_nod)
{
	t_nod	*n;

	n = malloc(sizeof(t_nod));
	init_nod(n);
	n->typ = r_e;
	n->next = last_nod;
	n->copy = copy_nod;
	return (n);
}
