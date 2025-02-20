#include "export.h"

int ft_arg_check(char *c)
{
	if (ft_isalphanum1(c) == 0) //ko a corriger
		return(-1);
	if (ft_nb_str(c, "'") % 2 == 1)//simple quote//pas complet
		return(-1);
	//gerer les double quote : a faire --> oui..
	return(1);
}


int ft_exp_check(char *c)
{
	int		i;
	char	**arg;

	arg = NULL;
	if(ft_search_cins(c, '=') == -1)
	{
//		printf("cas pas de '=' \n");
		if (ft_isalphanum1(c) == 0)
			return(-1);
		return(2);
	}
	else
	{
		if (c[ft_search_cins(c, '=') - 1] == ' ' || c[ft_search_cins(c, '=') + 1] == ' ')
			return(-1); //utile?
		arg = ft_split(c, '=');
		if (ft_isalphanum1(arg[0]) == 0)
			return(-1);
		i = 0;
		while(arg[i])
		{
			if(ft_arg_check(arg[i]) == -1)
				return(-1);
			i++;
		}
	}
//	printf("arg de export sans erreur\n");
	free(arg);
	return(1);
}

int main(int argc, char **argv, char **env)
{
	int i;
	char **new_env = NULL;
	char *new_arg;


	if(argc <= 1)
		return(-1);

	check_quote(argv[1]);

	if(argc == 1)
		{
			printf("afficher ENV");
		}
//	print_2c(argv);
//	print_2c(env);
	i = 0;
	i = ft_exp_check(argv[1]);
	if (i == -1)
	{
//		printf("erreur\n");
		return(-1);
	}
	else if (i == 2)
	{
		new_arg = ft_strjoin(argv[1], "=\'\'");
//		printf("new_arg = %s\n", new_arg);
		argv[1] = new_arg;
//		printf("argv[1] = %s\n", argv[1]);
	}

	i = arg_exist(env, argv[1]);
	if(i >= 0)
	{
//		printf("arg exist, env[%d] = %s\n", i, env[i]);
		env[i] = argv[1];
//		print_2c(env);
	}
	else
	{
//		printf("arg exist pas\n");
		new_env = ft_strjoin_21(env, argv[1]);
		env = new_env;
//		print_2c(env);
	}
	return (0);
}
