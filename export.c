#include "export.h"

int	exportable(char *c)
{
	int		i;
	char	**arg;
	int		n;
	char	*c_tmp;

	arg = NULL;
	n = ft_search_cins(c, '='); //si plusieurs =
	if(n == -1)
	{
		printf("cas pas de '=' \n");
		if (is_ven(c) == 0)
			return(-1);
		return(2);
	}
	else
	{
		if (c[n] == ' ' || c[n + 1] == ' ')
			return(-1); //utile?
		arg = ft_split(c, '='); //a tester : si plusieurs =
		if (is_ven(arg[0]) == 0)
			return(-1);

		c_tmp = format_txt(arg[1]);
		printf("c_tmp = %s\n", c_tmp);
		if(is_vev(c_tmp) == 0)
			{printf("pb env value"); return(-1);}
	}
//	printf("arg de export sans erreur\n");
	free(arg);
	return(1);
}

int	check_argc(int argc, char **env)
{
	if(argc <= 0)
		return(-1);
	if(argc == 1)
	{
		print_2c(env); //verifier le retour?
		exit(EXIT_SUCCESS);
	}
	if(argc == 2)
	{
		return (0);
	}
	return(-1);
}
int main(int argc, char **argv, char **env)
{
	int i;
	char *arg1;

	if(check_argc(argc, env) != 0)
		return(check_argc(argc, env));
	arg1 = format_txt(argv[1]);
//	if(arg1 == NULL)
//		exit(EXIT_FAILURE);
//	printf("arg1 = %s\n", arg1);
//	i = exportable(arg1);
//	if (i == -1)
//		return(-1);
//	else if (i == 2)
//		arg1 = ft_strjoin(arg1, "=\'\'");
///	format_txt(argv[1]);

	i = arg_exist(env, arg1);
	if(i >= 0)
		env[i] = arg1; //leaks??
	else
		env = ft_strjoin_21(env, arg1);
//	print_2c(env);
	return (0);
}


//		printf("arg exist, env[%d] est : %s\n", i, env[i]);
