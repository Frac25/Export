#ifndef EXPORT_H
# define EXPORT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//# include <errno.h>

# define DQ 34 //doubles quote
# define SQ 39 //simples quote

typedef enum typ // attention il faut mettre a jour le tableau en cas de modif
{
	d_q,// 0 double quote
	txt,// 1 text
	prg,// 2 program
	arg,// 3 argument
	ope,// 4 operator
	e_v,// 5 environnemnt variable
	s_q,// 6 simple quote
	und,// 7 undefined
	r_e,// 8 row extract
	evn,// 9 e_v name
	evv,// 10 e_v value
	equ,// 11 =
	pip,// 12 |
}	t_typ;

typedef struct data
{
	t_typ	typ2;
	int		nbeq;//nb_equal
	int		errnum;
}	t_data;

typedef struct nod
{
	struct nod	*next;
	struct nod	*prev;
	struct nod	*detail;
	struct nod	*copy;
	struct nod	*last;
	int			nod_size;
	int			level;
	int			index;
	t_typ		typ;
	char		*c;
	t_data		*d;
}	t_nod;

//export
int		check_argc(int argc, char **env);
char	**export(char *arg, char **env);
char	**insert_exp(char *name,char *value,char **env);

//extract
t_nod	*extract_if(t_nod *n, t_nod *n_e, int (*is_)(t_nod*));

int		if_ev_name(t_nod *n);
int		if_ev_value(t_nod *n);
char	*nod_to_txt_e(t_nod *n);
//t_nod	*extract_if27(t_nod *n, int (*f)(t_nod*));
//t_nod	*extract(t_nod *n, t_nod *n_e);
//char	*nod_to_txt(t_nod *n, char *c);

//ft_split
char	**ft_split(char const *s, char c);

//lib
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *str, const char *s, int len);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, int n);

//lib_m
char	*ft_strjoin2(char *s1, char *s2);
int		ft_strcmp2(const char *s1, const char *s2);
char	*ft_strjoin3(char const *s1, char const *s2, char const *s3);

//nod
void	init_nod(t_nod *n);
t_nod	*add_nod(t_typ typ, int l, char *c, int i, t_nod *last_nod);
void	free_nod(t_nod *n);
int		close_nod(t_nod *n);
t_nod	*add_nod_e(t_nod *copy_nod, t_nod *last_nod);

//parsing
t_nod	*parsing(char *c);
int		check_quote(t_nod *n, int quote);

//print_nod
void	print_nod(t_nod *n);
void	print_nod_l(t_nod *n);
void	print_nod0(t_nod *n);
void	print_nod_d(t_nod *n);
void	print_nod_e(t_nod *n);

//provide
int		prov_al_nbeq(t_nod *n, int nbeq);
int		prov_al_level(t_nod *n, int level);

int		prov_ll_typ2(t_nod *n);
int		prov_typ2(t_nod *n);

//read
void	read_ll_error(t_nod *n);
void	read_error(t_nod *n);

//replace
int		replace_ev(t_nod *n, char **env);
int		replace_ev_ll(t_nod *n, char **env);

//separate

int		sep_quote(t_nod *n, t_typ typ, int sep, int i);
int		sep_char(t_nod *n, t_typ typ, int sep, int i);
int		sep_level1(t_nod *n);
int		sep_level2_2(t_nod *n, t_typ typ, int sep, int i);
int		sep_ll_level2(t_nod *n);
int		sep_level2(t_nod *n);

//utils
int		ft_search_cins(char *s, char c);
int		ft_nb_char(char *s, char c);
int		ft_nb_str(char *s, char *c);

//utils2.c
char	**add_c_to_c2(char *s1, char **s2);
int		arg_exist(char *s1, char **s2);

//utils_2
void	print_2c(char **c);
char	**ft_strjoin_2(char **s1, char **s2);
int		size_2(char **c);
char	**ft_copy_2(char **s1);
void	free_2(char **c);

//utils_is
int		is_evn(char *c);
int		is_evn_c(char c);
int		is_evv(char *c);
int		is_evv_c(char c);
int		is_ev(t_nod *n);

int		is_num(char c);
#endif
