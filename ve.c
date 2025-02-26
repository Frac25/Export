#include "export.h"


int	sep_ve_ll(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n;
	i = 0;
//	printf("n->nod_size = %d\n", n->nod_size);
	while(i < n->nod_size)
	{
		if(n_tmp->detail == NULL)
			sep_ve(n_tmp);
		else
			sep_ve_ll(n_tmp->detail);
		n_tmp = n_tmp->next;
		i++;
	}
	return(0);
}

int	sep_ve(t_nod *n)
{
	int		i;
	int		l;
	t_nod	*n_d;
	char	*typ[] = {"d_q", "txt", "prg", "arg", "ope", "v_e", "s_q", "und"};

//	print_nod0(n);
	n_d = NULL;
	i = 0;

	if(n->typ == 0 || n->typ == 1)
	{

		while(n->c[i])
		{
			if(n->c[i] == 36) //dollars
			{
				i++;
				if (ft_isnum(n->c[i]) == 1)
					return(10);//a revoir
				l = 0;
				while(n->c[i] && is_ven_c(n->c[i]) == 1)
				{
					i++;
					l++;
				}
				if(l > 0)
					n_d = add_nod(v_e, l, n->c, i, n_d);
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
					n_d = add_nod(txt, l, n->c, i, n_d);
			}
		}
	}
	close_node(n_d);
	n->detail = n_d;

	return(0);
}

int	replace_ve_ll(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n;
	i = 0;
	while(i < n->nod_size)
	{
		if(n_tmp->detail == NULL && n_tmp->typ == 5)
			replace_ve(n_tmp);
		else if(n_tmp->detail != NULL)
			replace_ve_ll(n_tmp->detail);
		n_tmp = n_tmp->next;
		i++;
	}
	return(0);
}

int	replace_ve(t_nod *n)
{
	char *ve = "SYLVAIN";

//	if (n->typ == v_e && 1)//a completer
//		exit(0); //cas export z$USERa, a verifier

//	if(n->typ != v_e)
//		printf("erreur : pas une v-e");
	free(n->c);
	n->c = ft_strdup(ve);
	return(0);
}



//./export "txt1'q1\$USER.q2'txt2\$USER.txt3\"dq1\$USER.dq2\"txt4"
