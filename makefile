NAME = export

PROG =	export\
		extract\
		ft_split\
		lib\
		lib_m\
		nod\
		parsing\
		print_nod\
		provide\
		read\
		replace\
		separate\
		utils_2c\
		utils_is\
		utils\
		utils2\


SRC = $(addsuffix .c, $(PROG))

OBJ = $(addprefix obj/, $(addsuffix .o, $(PROG)))

CC = cc

CFLAGS = -Wall -Wextra -Werror -g
#CFLAGS = -g

obj/:
			mkdir -p obj

all :		obj/ $(NAME)

$(NAME) :	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)

obj/%.o :	%.c | obj/
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
