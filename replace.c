#include "export.h"

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

	arg = NULL;
	i = 0;
	while (env[i])
	{
		arg = ft_split(env[i], '=');
		if (ft_strcmp2(arg[0], n->c) == 0)
		{
			free(n->c);
			n->c = ft_strdup(arg[1]);
			free_2(arg);
			return (0);
		}
		free_2(arg);
		i++;
	}
	free(n->c);
	n->c = ft_strdup("");
	return (-1);
}
