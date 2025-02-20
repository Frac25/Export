#include "export.h"

int	ft_isalphanum1(char *c)
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

int	ft_isalphanum_c(char c)
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

int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return(1);
	return (0);
}