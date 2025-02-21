#include "export.h"

int	sep_ve(t_nod *n)
{
	int		i;
	int		l;
	t_nod	*n_d;

	n_d = NULL;
	i = 0;
	while(n->c[i])
	{
		if(n->c[i] == 36) //dollars
		{
			i++;
			if (ft_isnum(n->c[i]) == 1)
				return(10);
			l = 0;
			while(n->c[i] && is_env_value_c(n->c[i]) == 1)
			{
				i++;
				l++;
			}
			if(l > 0)
			{
				n_d = add_nod(v_e, l, n->c, i, n_d);
			}
			replace_ve(n_d);
//			printf("est une variable d env, n->c[i] = %c et l = %d\n", n->c[i], l);
		}
		else
		{
			l = 0;
			while(n->c[i] && n->c[i] != 36)
			{
				i++;
				l++;
			}
			if(l > 0)
			{
				n_d = add_nod(txt, l, n->c, i, n_d);
			}
//			printf("pas une variable d env, n->c[i] = %c et l = %d\n", n->c[i], l);
		}
	}
	close_node(n_d);
	n->detail = n_d;

	return(0);
}


int	replace_ve(t_nod *n)
{
	char *ve = "SYLVAIN";

	if(n->typ != v_e)
		printf("erreur : pas une v-e");
	free(n->c);
	n->c = ft_strdup(ve);
	return(0);
}


//./export "txt1'q1\$USER.q2'txt2\$USER.txt3\"dq1\$USER.dq2\"txt4"
