#include "export.h"

int	sep_ev_ll(t_nod *n)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n;
	i = 0;
	while (i < n->nod_size)
	{
		if (n_tmp->detail == NULL)
			sep_ev(n_tmp);
		else
			sep_ev_ll(n_tmp->detail);
		n_tmp = n_tmp->next;
		i++;
	}
	return (0);
}

int	sep_ev(t_nod *n)
{
	int		i;
	int		l;
	t_nod	*n_d;

	n_d = NULL;
	i = 0;
	if (n->typ == d_q || n->typ == txt)
	{
		while (n->c[i])
		{
			if (n->c[i] == '$')
			{
				i++;
				if (ft_isnum(n->c[i]) == 1)
				{
					perror("commence par un numerique, KO");
					return (10);//SDU
				}
				l = 0;
				while (n->c[i] && is_evn_c(n->c[i]) == 1)
				{
					i++;
					l++;
				}
				if (l > 0)
					n_d = add_nod(e_v, l, n->c, i, n_d);
			}
			else
			{
				l = 0;
				while (n->c[i] && n->c[i] != '$')
				{
					i++;
					l++;
				}
				if (l > 0)
					n_d = add_nod(txt, l, n->c, i, n_d);
			}
		}
	}
	close_node(n_d);
	n->detail = n_d;
	return (0);
}

int	replace_ev_ll(t_nod *n, char **env)
{
	int		i;
	t_nod	*n_tmp;

	n_tmp = n;
	i = 0;
	while (i < n->nod_size)
	{
		if (n_tmp->detail == NULL && n_tmp->typ == e_v)
			replace_ev(n_tmp, env);
		else if (n_tmp->detail != NULL)
			replace_ev_ll(n_tmp->detail, env);
		n_tmp = n_tmp->next;
		i++;
	}
	return (0);
}

int	replace_ev(t_nod *n, char **env)
{
	int		i;
	char	**arg;

//	*ev = "SYLVAIN";

//	if(n->typ != e_v)
//		printf("erreur : pas une v-e");

//	if (n->typ == e_v && 1)//a completer SDU
//		exit(0); //cas export z$USERa, a verifier
	arg = NULL;
	i = 0;

	while(env[i])
	{
//		if(i == 1) {printf("env[%d] = %s\n", i, env[i]);}
		arg = ft_split(env[i], '=');
//		if(i == 1) {printf("arg[0] = %s et arg[1] = %s et n->c = %s\n", arg[0], arg[1], n->c);}
		if (ft_strcmp2(arg[0], n->c) == 0)
		{
			free(n->c);
			n->c = ft_strdup(arg[1]);
			free(arg);
			return(0);
		}
		free(arg);
		i++;
	}
//	printf("ev non trouvee\n");
	free(n->c);
	n->c = ft_strdup("");
	return (-1);
}

//./export "txt1'q1\$USER.q2'txt2\$USER.txt3\"dq1\$USER.dq2\"txt4"
