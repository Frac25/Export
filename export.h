#ifndef EXPORT_H
# define EXPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum typ
{
	d_quote,
	txt,
	prog,
	arg,
	operator,
} t_typ;

typedef struct nod
{
	struct nod *next;
	struct nod *prev;
	char *c;
	int size;
	t_typ typ;
	int level;
	int index;
}	t_nod;


void	print_2c(char **c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *str, const char *s, size_t len);
size_t	ft_strlen(const char *s);

int		ft_search_cins(char *s, char c);
int		ft_isnum(char c);
char	**ft_split(char const *s, char c);
int		ft_nb_char(char *s, char c);
int		ft_nb_str(char *s, char *c);
char	**ft_strjoin_2(char **s1, char **s2);
char	**ft_strjoin_21(char **s1, char *s2);
int		arg_exist(char **s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		size_2(char **c);

//utils
int		ft_isalphanum1(char *c);
int		ft_isalphanum_c(char c);




//quote
int		check_quote(char *c);
int		sep_quote(char *c);
t_nod	*add_nod(t_typ typ, int l, char *c, int i, t_nod *last_nod);
void	print_nod(t_nod *nod);

//var_env
int	var_env(t_nod *n);
#endif
