NAME = export

PROG =	export\
		format\
		ft_split\
		lib\
		lib_m\
		node\
		print_nod\
		quote\
		utils_2c\
		utils_is\
		utils\
		utils2\
		var_env\

SRC = $(addsuffix .c, $(PROG))

OBJ = $(addsuffix .o, $(PROG))

CC = cc

#CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -g

all :		$(NAME)

$(NAME) :	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)

%.o :		%.c
			$(CC) -c $< $(CFLAGS) -o $@

clean :
			rm -f $(OBJ)

fclean : 	clean
			rm -f $(NAME)

re :		fclean all

a :			all clean

valgrind :	$(NAME)
			valgrind --leaks-check=full --show-leaks-kinds=all --track-origins=yes ./$(NAME)

.PHONY :	all clean fclean re a valgrind
