#include "export.h"

char	*format_txt(char *c)
{
	t_nod *n;
	t_nod *res;

	n = add_nod(und, ft_strlen(c), c, ft_strlen(c), NULL);
	close_node(n);
	check_quote(n);
	sep_quote(n);
	sep_ve_ll(n);
	replace_ve_ll(n);
	if (is_env_ll(n) == -1)
		return (NULL);
	print_nod_l(n,0);

	res = extract(n, NULL);
	if(res == NULL)
		exit(EXIT_SUCCESS);
	close_node(res);
	printf("\n");
	print_nod_e(res);

	exit(EXIT_SUCCESS);
//	printf("nod_to_txt = %s", nod_to_txt(sep_quote(c), NULL));
	return (nod_to_txt(n, NULL));
}

char	*nod_to_txt(t_nod *n, char *c)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n->prev;
	i = 0;
//	printf("n->nod_size = %d\n", n->nod_size);
	while(i < n->nod_size)
	{
		if(n_tmp->detail == NULL)
			c = ft_strjoin2(c, n_tmp->c); // il faudra free c dans join
		else
			c = nod_to_txt(n_tmp->detail, c);
		n_tmp = n_tmp->prev;
		i++;
	}
//	printf("c3 = %s\n", c);
	return(c);
}

int	is_env_ll(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n;
	i = 0;
	while(i < n->nod_size)
	{
		if(n_tmp->detail == NULL)
		{
			if(is_env(n_tmp) == -1)
				return (-1);
		}
		else
		{
			if(is_env_ll(n_tmp->detail) == -1)
				 return (-1);
		}
		n_tmp = n_tmp->next;
		i++;
	}
	return(0);
}

int	is_env(t_nod *n)
{
	if(n->eq == 0)
		n->i_e = is_env_name(n->c);
	else if (n->eq == 1)
		n->i_e = is_env_value(n->c);
	else
		return (-1);
	return (0);
}
// ./export "\"test\""

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
			if(n_tmp->i_e == 0)
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
