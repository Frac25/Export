#include "export.h"

char	*format_txt(char *c)
{
	t_nod *n;


	n = add_nod(und, ft_strlen(c), c, ft_strlen(c), NULL);
	close_node(n);
	print_nod_d(n);
	check_quote(n);
	sep_quote(n);
	print_nod_l(n,0);

	sep_ve(n);
	replace_ve(n);
//	printf("nod_to_txt = %s", nod_to_txt(sep_quote(c), NULL));
	return (nod_to_txt(n, NULL));
}

char	*nod_to_txt(t_nod *n, char *c)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n->prev;
	i = 0;
	c = NULL;
//	printf("n->nod_size = %d\n", n->nod_size);
	while(i < n->nod_size)
	{
		if(n_tmp->detail == NULL)
			c = ft_strjoin2(c, n_tmp->c); // il faudra free c dans join
		else
			c = nod_to_txt(n_tmp->detail, NULL);
		n_tmp = n_tmp->prev;
		i++;
	}
//	printf("c3 = %s\n", c);
	return(c);
}

// ./export "\"test\""
