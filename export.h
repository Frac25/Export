#ifndef EXPORT_H
# define EXPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum typ // attention il faut mettre a jour le tableau en cas de modif --> a simplifier
{
	d_q,//double quote
	txt,
	prg,
	arg,
	ope,//operator
	v_e,//variable environnemnt
	s_q,//simple quote
	und,//undifined
	r_e,//row extract
} t_typ;

typedef struct nod
{
	struct nod *next;
	struct nod *prev;
	int nod_size;
	struct nod *detail;
	struct nod *copy;
	struct nod *last;
	char *c;
	int size;
	t_typ typ;
	int level;
	int index;
	int eq;//equal;
	int i_e;//is_env;
}	t_nod;

//export
int		exportable(char *c);
int		check_argc(int argc, char **env);

//format

char	*format_txt(char *c);
char	*nod_to_txt(t_nod *n, char *c);
int		is_env_ll(t_nod *n);
int		is_env(t_nod *n);
t_nod	*extract(t_nod *n, t_nod *n_e);

//ft_split
char	**ft_split(char const *s, char c);

//insert
char	**ft_strjoin_21(char **s1, char *s2);
int		arg_exist(char **s1, char *s2);


//lib
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *str, const char *s, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//lib_m
char	*ft_strjoin2(char *s1, char *s2);//pas du std

//node
void	init_nod(t_nod *n);
t_nod	*add_nod(t_typ typ, int l, char *c, int i, t_nod *last_nod);
int		close_node(t_nod *n);
t_nod	*add_nod_e(t_nod *copy_nod, t_nod *last_nod);

//print_nod
void	print_nod(t_nod *n);
void	print_nod_l(t_nod *n, int d);
void	print_nod0(t_nod *n);
void	print_nod_d(t_nod *n);
void	print_nod_e(t_nod *n);

//quote
int		exit_quote(int i);
int		check_quote(t_nod *n);
int		sep_quote(t_nod *n);

//utils
int		ft_search_cins(char *s, char c);
int		ft_nb_char(char *s, char c);
int		ft_nb_str(char *s, char *c);

//utils_2
void	print_2c(char **c);
char	**ft_strjoin_2(char **s1, char **s2);
int		size_2(char **c);
char	**ft_copy_2(char **s1);
void	free_2(char **c);

//utils_is
int		is_env_name(char *c);
int		is_env_name_c(char c);
int		is_env_value(char *c);
int		is_env_value_c(char c);
int		ft_isnum(char c);

//ve
int	sep_ve_ll(t_nod *n);
int	sep_ve(t_nod *n);
int	replace_ve(t_nod *n);
int	replace_ve_ll(t_nod *n);




#endif
