#include "export.h"

/**
 * @brief format des noms de variable d environnement : maj , min, _ et num sauf pour la premiere lettre.
 *
 * @param c
 * @return int
 * @result 1 si ok, sinon 0
 */
int	is_ven(char *c)
{
	int	i;
	int	ok;

	i = 0;
	if (c[0] >= '0' && c[0] <= '9')
		return(0);
	while(c[i])
	{
		ok = 0;
		if (c[i] >= 'A' && c[i] <= 'Z')
			ok++;
		else if (c[i] >= 'a' && c[i] <= 'z')
			ok++;
		else if (c[i] >= '0' && c[i] <= '9')
			ok++;
		else if (c[i] == '_')
			ok++;
		if(ok == 0)
			return(0);
		i++;
	}
	return (1);
}

/**
 * @brief format des noms de variable d environnement : maj , min, _ et num ,
 * ne verifie pas la premiere lettre.
 *
 * @param c
 * @return int
 * @result 1 si ok, sinon 0
 */
int	is_ven_c(char c)
{
	if (c >= 'A' && c <= 'Z')
		return(1);
	else if (c >= 'a' && c <= 'z')
		return(1);
	else if (c >= '0' && c <= '9')
		return(1);
	else if (c == '_')
		return(1);
	return (0);
}

/**
 * @brief format des valeurs des variables d environnement :  maj , min, num, '_' '.' ',' ':'
 *
 * @param c
 * @return int
 * @result 1 si ok, sinon 0
 */
int	is_vev_c(char c)
{
	if (c >= 'A' && c <= 'Z')
		return(1);
	else if (c >= 'a' && c <= 'z')
		return(1);
	else if (c >= '0' && c <= '9')
		return(1);
	else if (c == '_' || c == '.' || c == ',' || c == ':')
		return(1);
	return (0);
}

/**
 * @brief format des valeurs des variables d environnement :  maj , min, num, '_' '.' ',' ':'
 *
 * @param c
 * @return int
 * @result 1 si ok, sinon 0
 */
int	is_vev(char *c)
{
	int i;
	int ok;

	i = 0;
	while (c[i])
	{
		ok = 0;
		if (c[i] >= 'A' && c[i] <= 'Z')
			ok++;
		else if (c[i] >= 'a' && c[i] <= 'z')
			ok++;
		else if (c[i] >= '0' && c[i] <= '9')
			ok++;
		else if (c[i] == '_' || c[i] == '.' || c[i] == ',' || c[i] == ':')
			ok++;
		if(ok == 0)
			return(0);
		i++;
	}
	return (1);
}

/**
 * @brief revoie 1 si numerique
 *
 * @param c
 * @return int
 */
int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return(1);
	return (0);
}
