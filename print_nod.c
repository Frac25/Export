#include "export.h"

/**
 * @brief 	print le char* du nod
 *
 * @param n
 */
void	print_nod0(t_nod *n)
{
	t_nod	*n_tmp;

	n_tmp = n;
	if (n_tmp)
		printf("%s\n", n_tmp->c);
}

/**
 * @brief print le char* de tous les nod du meme level
 *
 * @param n
 */
void	print_nod(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n->prev;
	i = 0;
	while (i < n->nod_size)
	{
		printf("%s\n", n_tmp->c);
		n_tmp = n_tmp->prev;
		i++;
	}
}

/**
 * @brief detail en ligne pour print_nod_l
 *
 * @param n
 */
void	print_nod_d2(t_nod *n)
{
	char	*typ[] = {"d_q", "txt", "prg", "arg", "ope", "e_v", "s_q", "und", "r_e", "evn", "evv", "equ", "pip"};
	int		i;
	int		j;

	j = 0;
	while (j++ < n->level)
		printf("  ");
	printf("%s : %s", typ[n->typ], n->c);
	i = (ft_strlen(n->c) + 6 + (n->level * 2)) / 8;
	while (i <= 2)
	{
		printf("	");
		i++;
	}
	printf(" level = %d   size = %d", n->level, n->nod_size);
	printf("   nbeq = %d   typ2 = %s   err = %d", n->d->nbeq, typ[n->d->typ2], n->d->errnum);
	printf("\n");
}

/**
 * @brief print les nod et tout les details avals
 *
 * @param n
 * @param d decale l affichage
 */
void	print_nod_l(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n->prev;
	i = 0;
	while (i < n->nod_size)
	{
		print_nod_d2(n_tmp);
		if (n_tmp->detail != NULL)
			n_tmp = n_tmp->prev;
		i++;
	}
}

/**
 * @brief print le char* de tous les nod extrait
 *
 * @param n
 */
void	print_nod_e(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n->prev;
	i = 0;
	while (i < n->nod_size)
	{
		printf("%s\n", n_tmp->copy->c);
		n_tmp = n_tmp->prev;
		i++;
	}
}
