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

//int TOTO(t_nod n, char **env);
//{
//	printf("test");
//}


char **export(char *arg, char **env)
{
	int		i;
	t_nod	*n;
	char	*exp;
	char	*name;
	char	*value;

	n = parsing(arg);
	replace_ev_ll(n,env);
	name = nod_to_txt_e(extract_if(n, NULL, if_ev_name));
	value = nod_to_txt_e(extract_if(n, NULL, if_ev_value));
	if (value == NULL)
		exp = ft_strjoin(name, "=\'\'");
	else
		exp = ft_strjoin3(name, "=", value);
	printf("exp1 = %s\n", exp);
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
	print_2c(env); // attention ne modifie pas le pointeur d originne
	printf("exp = %s\n\n", exp);
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
		printf("passe");
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
