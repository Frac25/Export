#include "export.h"

char	*format_txt(char *c)
{
	t_nod *n;


	n = add_nod(und, ft_strlen(c), c, ft_strlen(c), NULL);
	close_node(n);
	check_quote(n);
	sep_quote(n);
	sep_ve_ll(n);
	replace_ve_ll(n);
	if (is_env_ll(n) == -1)
		return (NULL);
	print_nod_l(n,0);
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
