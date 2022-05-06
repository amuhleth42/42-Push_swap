NAME	= push_swap

FLAGS	= -Wall -Wextra -Werror -Ofast -g
INCL	= -I. -I./libft
LIB		= -L./libft -lft

SRCS	= $(addprefix srcs/,	\
			moves.c				\
			moves2.c			\
			moves3.c			\
			parsing.c			\
			exit.c				\
			utils_test.c		\
			sort.c				\
			list_opti.c			\
			wheel_sort.c		\
			test.c)

all :		$(NAME)

$(NAME) :	libft.a
	gcc $(FLAGS) $(INCL) $(LIB) $(SRCS) -o $(NAME)

libft.a :
	make -C ./libft

clean :
	make fclean -C ./libft
	rm $(NAME)

fclean :	clean

re :		fclean all

.PHONY :	re all clean fclean
