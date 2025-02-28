#ifndef EXPORT_H
# define EXPORT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
	int		iev;//is_ev
	int		nbeq;//nb_equal
}	t_data;

typedef struct nod
{
	struct nod	*next;
	struct nod	*prev;
	struct nod	*detail;
	struct nod	*copy;
	int			nod_size;
	int			level;
	int			index;
	t_typ		typ;
	char		*c;
	t_data		*d;
}	t_nod;

//export
int		check_argc(int argc, char **env);
//int		export(char *arg, char **env);
char **export(char *arg, char **env);

//extract
t_nod	*extract_if(t_nod *n, t_nod *n_e, int (*is_)(t_nod*));
t_nod	*extract(t_nod *n, t_nod *n_e);
int		if_ev_name(t_nod *n);
int		if_ev_value(t_nod *n);

//ev
int		sep_ev_ll(t_nod *n);
int		sep_ev(t_nod *n);
int		replace_ev(t_nod *n, char **env);
int		replace_ev_ll(t_nod *n, char **env);

//format
t_nod	*parsing(char *c);
char	*nod_to_txt(t_nod *n, char *c);
char	*nod_to_txt_e(t_nod *n);

//ft_split
char	**ft_split(char const *s, char c);

//insert
char	**ft_strjoin_21(char *s1, char **s2);
int		arg_exist(char *s1, char **s2);

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

//print_nod
void	print_nod(t_nod *n);
void	print_nod_l(t_nod *n);
void	print_nod0(t_nod *n);
void	print_nod_d(t_nod *n);
void	print_nod_e(t_nod *n);

//provide
int		provide_nbeq(t_nod *n, int nbeq);
int		provide_level(t_nod *n, int level);

int		is_ev_ll(t_nod *n);
int		is_ev(t_nod *n);

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
int		is_evn(char *c);
int		is_evn_c(char c);
int		is_evv(char *c);
int		is_evv_c(char c);
int		ft_isnum(char c);

#endif
