#include "export.h"

int	check_argc(int argc, char **env)
{
	if (argc <= 0)
		return (-1);
	if (argc == 1)
	{
		print_2c(env); //SDU verifier le retour?
		exit(EXIT_SUCCESS);
	}
	return (0);
}

char	**insert_exp(char *name, char *value, char **env)
{
	char	*exp;
	int		i;

	if (value == NULL)
		exp = ft_strjoin(name, "=\'\'");
	else
		exp = ft_strjoin3(name, "=", value);
	i = arg_exist(name, env);
	if (i != -1)
	{
		printf("arg exist\n");
		free(env[i]); //checker
		env[i] = exp; //checker
	}
	else
	{
		printf("arg exist pas \n");
		env = add_c_to_c2(exp, env);
	}
	return (env);
}

char	**export(char *arg, char **env)
{
	t_nod	*n;
	char	*name;
	char	*value;

	n = parsing(arg);
	replace_ev_ll(n, env);
	print_nod_l(n);
	name = nod_to_txt_e(extract_if(n, NULL, if_ev_name)); //SDU mettre NULL en interne dans n
	if (is_evn(name) == -1 || is_num(name[0]) == 1)
	{
		write(2, "not an identifier\n", 18);
		free_nod(n);
		free(name);
		exit(0);
	}
	value = nod_to_txt_e(extract_if(n, NULL, if_ev_value));
	env = insert_exp(name, value, env);
	print_2c(env);
	free_nod(n);
	free(name);
	free(value);
	return (env);
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	char	**env2;

	env2 = ft_copy_2(env);
	if (check_argc(argc, env2) != 0)
		return (check_argc(argc, env2));
	i = 1;
	while (argv[i])
	{
		env2 = export(argv[i], env2);
		i++;
	}
	free_2(env2);
	return (0);
}
