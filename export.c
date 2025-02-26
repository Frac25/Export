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
		if (is_evn(c) == 0)
			return(-1);
		return(2);
	}
	else
	{
		if (c[n] == ' ' || c[n + 1] == ' ')
			return(-1); //utile?
		arg = ft_split(c, '='); //a tester : si plusieurs =
		if (is_evn(arg[0]) == 0)
			return(-1);

		c_tmp = format_txt(arg[1]);
		printf("c_tmp = %s\n", c_tmp);
		if(is_evv(c_tmp) == 0)
			{printf("pb ev"); return(-1);}
	}
//	printf("arg de export sans erreur\n");
	free(arg);
	return(1);
}

int	check_argc(int argc, char **ev)
{
	if(argc <= 0)
		return(-1);
	if(argc == 1)
	{
		print_2c(ev); //verifier le retour?
		exit(EXIT_SUCCESS);
	}
	if(argc == 2)
	{
		return (0);
	}
	return(-1);
}
int main(int argc, char **argv, char **ev)
{
	int i;
	char *arg1;

	if(check_argc(argc, ev) != 0)
		return(check_argc(argc, ev));
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

	i = arg_exist(ev, arg1);
	if(i >= 0)
		ev[i] = arg1; //leaks??
	else
		ev = ft_strjoin_21(ev, arg1);
//	print_2c(ev);
	return (0);
}


//		printf("arg exist, ev[%d] est : %s\n", i, ev[i]);



//export NOM_txt1'q1q2'txt2$USER"dq1$USERdq2"txt4=VALEUR_txt1'q1.,:q2'txt2$USER"dq1$USER.dq2"txt4
//./export "NOM_txt1'q1q2'txt2\$USER\"dq1\$USERdq2\"txt4"="VALEUR_txt1'q1.,:q2'txt2\$USER\"dq1\$USER.dq2\"txt4"

//test : export NOM_txt1'q1q2'txt2$USER  "     dq1 $USERdq2 "txt4  =VALEUR_txt1'q1.,:q2'txt2$USER"       dq1 $USER       .dq2 "txt4
//resultat :    NOM_txt1 q1q2 txt2sylvainduboisdq1           txt4  =VALEUR_txt1 q1.,:q2 txt2sylvainduboisdq1sylvaindubois.dq2  txt4
//T   ./export "NOM_txt1'q1q2'txt2\$USER\"     dq1\$USERdq2\"txt4"="VALEUR_txt1'q1.,:q2'txt2\$USER\"     dq1\$USER       .dq2\"txt4"



