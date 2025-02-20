#include "export.h"

int	var_env(t_nod *n)
{
	int i;
	int l;
//	printf("passe 0\n");
	i = 0;
	while(n->c[i])
	{
		if(n->c[i] == 36) //dollars
		{

			i++;
			printf("passe10 n->c[i] = %c\n", n->c[i]);
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
				var_replace(n, i, l);
//			printf("n->c[i] = %c et l = %d\n", n->c[i], l);

//				;
		}
		else
			i++;
	}
	return(0);
}


int var_replace(t_nod *n, int i, int l)
{
	char var = "SYLVAINDUBOIS";





}

