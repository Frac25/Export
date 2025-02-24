#include "export.h"

/**
 * @brief 	print le char* du nod
 *
 * @param n
 */
void	print_nod0(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n;
	i = 0;
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
	printf("n->nod_size = %d\n", n->nod_size);
	while(i < n->nod_size)
	{
		printf("%s\n", n_tmp->c);
		n_tmp = n_tmp->prev;
		i++;
	}
}

/**
 * @brief print les nod et tout les details avals
 *
 * @param n
 * @param d decale l affichage
 */
void	print_nod_l(t_nod *n, int d)
{
	int		i;
	int		j;
	t_nod	*n_tmp;
	char	*typ[] = {"d_q", "txt", "prg", "arg", "ope", "v_e", "s_q", "und"};

	n_tmp = n->prev;
	i = 0;
	while(i < n->nod_size)
	{
		j = 0;
		while(j++ < d)
			printf("  ");
		printf("%s : %s\n", typ[n_tmp->typ], n_tmp->c);
		if(n_tmp->detail != NULL)
			print_nod_l(n_tmp->detail, d + 1);
		n_tmp = n_tmp->prev;
		i++;
	}
}

/**
 * @brief print le detail du nod
 *
 * @param n
 */
void	print_nod_d(t_nod *n)
{
	printf("\nc = %s\n", n->c);
	printf("next = %p\n", n->next);
	printf("detail = %p\n", n->detail);
	printf("typ = %d\n\n", n->typ);
}

