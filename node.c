#include "export.h"

void	init_nod(t_nod *n)
{

	n->next = NULL;
	n->prev = NULL;
	n->detail = NULL;
	n->copy = NULL;
	n->nod_size = 0;
	n->level = 0;
	n->index = 0;
	n->typ = und;
	n->c = NULL;
	n->d = malloc(sizeof(t_data));
	n->d->typ2 = und;
	n->d->ive = 0;
}

int	close_node(t_nod *n)
{
	t_nod	*n_tmp;
	t_nod	*n_tmp2;
	int		i;

	i = 1;
	n_tmp = n;
	n_tmp2 = n;
	if (n == NULL)
		return(0);
	while(n_tmp->next != NULL)
	{
		n_tmp = n_tmp->next;
		n_tmp->prev = n_tmp2;
		n_tmp2 = n_tmp;
		i++;
	}
	n_tmp->next  = n;
	n_tmp->next->prev = n_tmp;
	n->nod_size = i;
	return(0);
}

/**
 * @brief crer un nod d'une liste chainee
 *
 * @param typ : type de contenu de la chaine de caractere c
 * @param l : nbr de caractere a extraire
 * @param c : chaine d originne
 * @param i : position du (dernier charactere + 1) a copier dans la chaine d originne
 * @param last_nod : nod precedant, a chainer
 * @return t_nod*
 */
t_nod	*add_nod(t_typ typ, int l, char *c, int i, t_nod *last_nod)
{
	t_nod	*n;
	int		j;

	n = malloc(sizeof(t_nod));
//	if (last_nod == NULL)
	init_nod(n);
	n->index++;//a suppr
	n->typ = typ;
	n->next = last_nod;
	n->c = malloc(sizeof(char) *(l + 1));
	n->c[l] = '\0';
	j = 1;
	while(j <= l)
	{
		n->c[l - j] = c[(i) - j];
		j++;
	}
	return(n);

}

/**
 * @brief ajoute un node d extraction
 *
 * @param copy_nod
 * @param last_nod
 * @return t_nod*
 */
t_nod	*add_nod_e(t_nod *copy_nod, t_nod *last_nod)
{
	t_nod	*n;
	int		j;

	n = malloc(sizeof(t_nod));
//	if (last_nod == NULL)
		init_nod(n);

	n->typ = 8;
	n->next = last_nod;
	n->copy = copy_nod;

	return(n);
}

