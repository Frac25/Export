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
	if (argc == 2)
	{
		return (0);
	}
	return (-1);
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	t_nod	*n;
	char	*exp;
	char	*name;
	char	*value;

	if (check_argc(argc, env) != 0)
		return (check_argc(argc, env));
	n = parsing(argv[1]);
	replace_ev_ll(n, env);
	name = nod_to_txt_e(extract_if(n, NULL, if_ev_name));
	value = nod_to_txt_e(extract_if(n, NULL, if_ev_value));
	if (value == NULL)
		exp = ft_strjoin(name, "=\'\'");
	else
		exp = ft_strjoin3(name, "=", value);
	i = arg_exist(name, env);
	if (i != -1)
	{
		free(env[i]);
		env[i] = exp;
	}
	else
		env = ft_strjoin_21(exp, env);
	print_2c(env);
	printf("exp = %s\n\n", exp);
	return (0);
}

//TEST :
//export NOM_txt1'q1q2'txt2$USER"dq1$USERdq2"txt4=VALEUR_txt1'q1.,:q2'txt2$USER"dq1$USER.dq2"txt4
//./export "NOM_txt1'q1q2'txt2\$USER\"dq1\$USERdq2\"txt4"="VALEUR_txt1'q1.,:q2'txt2\$USER\"dq1\$USER.dq2\"txt4"

//test :        export  NOM_txt1'q1q2'txt2 $USER  "    dq1 $USERdq2 "txt4  = VALEUR_txt1'q1.,:q2'txt2$USER"       dq1 $USER       .dq2 "txt4
//test sd :   ./export "NOM_txt1'q1q2'txt2\$USER\"     dq1\$USERdq2\"txt4" ="VALEUR_txt1'q1.,:q2'txt2\$USER\"     dq1\$USER       .dq2\"txt4"
//resultat :    		NOM_txt1 q1q2 txt2sylvainduboisdq1           txt4  = VALEUR_txt1 q1.,:q2 txt2sylvainduboisdq1sylvaindubois.dq2  txt4
//resultat sd : 		NOM_txt1 q1q2 txt2sylvainduboisdq1           txt4  = VALEUR_txt1 q1.,:q2 txt2sylvainduboisdq1sylvaindubois.dq2  txt4
