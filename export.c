#include "export.h"

int	check_argc(int argc, char **env)
{
	if (argc <= 0)
		return (-1);
	if (argc == 1)
	{
		print_2c(env); //verifier le retour?
		exit(EXIT_SUCCESS);
	}
	return(0) ;
}

int	insert_exp(char *name,char *value,char **env)
{
	char	*exp;
	int	i;

	if (value == NULL)
		exp = ft_strjoin(name, "=\'\'");
	else
		exp = ft_strjoin3(name, "=", value);
	i = arg_exist(name, env);
	if (i != -1)
	{
		printf("arg exist\n");
		free(env[i]);
		env[i] = exp;
	}
	else
	{
		printf("arg exist pas \n");
		env = ft_strjoin_21(exp, env);
	}
	print_2c(env);
	printf("exp = %s\n\n", exp);
	free(exp);
	return(0);
}

char	**export(char *arg, char **env)
{
	t_nod	*n;
	char	*name;
	char	*value;

	n = parsing(arg);
		printf("passe1\n");
	replace_ev_ll(n,env);//SDU pourquoi pb de definition de la fonction??
		printf("passe2\n");
	name = nod_to_txt_e(extract_if(n, NULL, if_ev_name)); //SDU mettre NULL en interne dans n
//	name = nod_to_txt_e(extract_if27(n, if_ev_name));
	printf("passe3, name = %s et name[0] = %c\n", name, name[0]);
	if(is_evn(name) == -1 || is_num(name[0]) == 1)
	{
		write(2, "not an identifier\n", 18);
//		free_nod(n);
//		free(name);
		exit(0);// a free SDU
	}
	printf("passe4\n");
	value = nod_to_txt_e(extract_if(n, NULL, if_ev_value));
	insert_exp(name, value, env); //SDU pourquoi pb de definition de la fonction??
	printf("passe5\n");
	free_nod(n);
	free(name);
	free(value);
	return (env);
}

int	main(int argc, char **argv, char **env)
{
	int		i;

	if (check_argc(argc, env) != 0)
		return (check_argc(argc, env));
	i = 1;
	while(argv[i])
	{
		env = export(argv[i], env);
		i++;
	}
	return (0);
}

//TEST :
//export NOM_txt1'q1q2'txt2$USER"dq1$USERdq2"txt4=VALEUR_txt1'q1.,:q2'txt2$USER"dq1$USER.dq2"txt4
//./export "NOM_txt1'q1q2'txt2\$USER\"dq1\$USERdq2\"txt4"="VALEUR_txt1'q1.,:q2'txt2\$USER\"dq1\$USER.dq2\"txt4"

//test :        export  NOM_txt1'q1q2'txt2 $USER  "    dq1 $USERdq2 "txt4  = VALEUR_txt1'q1.,:q2'txt2$USER"       dq1 $USER       .dq2 "txt4
//test sd :   ./export "NOM_txt1'q1q2'txt2\$USER\"     dq1\$USERdq2\"txt4" ="VALEUR_txt1'q1.,:q2'txt2\$USER\"     dq1\$USER       .dq2\"txt4"
//resultat :    		NOM_txt1 q1q2 txt2sylvainduboisdq1           txt4  = VALEUR_txt1 q1.,:q2 txt2sylvainduboisdq1sylvaindubois.dq2  txt4
//resultat sd : 		NOM_txt1 q1q2 txt2sylvainduboisdq1           txt4  = VALEUR_txt1 q1.,:q2 txt2sylvainduboisdq1sylvaindubois.dq2  txt4


// ./export "\"test\"" SDU a faire, KO
