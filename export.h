#ifndef EXPORT_H
# define EXPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum typ
{
	d_q,
	txt,
	prg,
	arg,
	ope,
	v_e,
	s_q,
} t_typ;

typedef struct nod
{
	struct nod *next;
	struct nod *prev;
	int nod_size;
	struct nod *detail;
	char *c;
	int size;
	t_typ typ;
	int level;
	int index;
}	t_nod;

//export
int		ft_arg_check(char *c);
int		ft_exp_check(char *c);

//ft_split
char	**ft_split(char const *s, char c);

//insert
char	**ft_strjoin_21(char **s1, char *s2);
int		arg_exist(char **s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//lib
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *str, const char *s, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin2(char *s1, char *s2);//pas du std

//node
void	init_nod(t_nod *n);
t_nod	*add_nod(t_typ typ, int l, char *c, int i, t_nod *last_nod);
int		close_node(t_nod *n);

//print_nod
void	print_nod(t_nod *n);
void	print_nod_l(t_nod *n, int d);
void	print_nod0(t_nod *n);
void	print_nod_d(t_nod *n);

//quote
int		check_quote(char *c);
t_nod	*sep_quote(char *c);
int		exit_quote(int i);
char	*format_txt(char *c);
char	*nod_txt(t_nod *n, char *c);

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
int		ft_isalphanum1(char *c);
int		ft_isalphanum_c(char c);
int		ft_isnum(char c);

//sep_ve
int	sep_ve(t_nod *n);
int	replace_ve(t_nod *n);

#endif
