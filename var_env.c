#include "export.h"

int	sep_ve(t_nod *n)
{
	int		i;
	int		l;
	t_nod	*n_d;

	n_d = NULL;
//	printf("passe 0\n");
	i = 0;
	while(n->c[i])
	{
		if(n->c[i] == 36) //dollars
		{
			i++;
//			printf("passe10 n->c[i] = %c\n", n->c[i]);
			if (ft_isnum(n->c[i]) == 1)
				return(10);
			l = 0;
			while(n->c[i] && ft_isalphanum_c(n->c[i]) == 1)
			{
//				printf("passe20\n");
				i++;
				l++;
			}
			if(l > 0)
			{
				n_d = add_nod(v_e, l, n->c, i, n_d);
			}
			replace_ve(n_d);
//			printf("est une variable d env, n->c[i] = %c et l = %d\n", n->c[i], l);
//			print_nod_d(n_d);
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
//			print_nod_d(n_d);
		}
	}
	close_node(n_d);
	n->detail = n_d;

	return(0);
}


int	replace_ve(t_nod *n)
{
	char *ve = "SYLVAINDUBOIS";

	if(n->typ != v_e)
		printf("erreur : pas une v-e");
	free(n->c);
	n->c = ve;
}


//./export "txt1'q1\$USER.q2'txt2\$USER.txt3\"dq1\$USER.dq2\"txt4"