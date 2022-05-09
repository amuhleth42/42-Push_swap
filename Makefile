NAME	= push_swap

FLAGS	= -Wall -Wextra -Werror -Ofast
INCL	= -I. -I./libft
LIB		= -L./libft -lft

SRCS	= $(addprefix srcs/,	\
			moves.c				\
			moves2.c			\
			moves3.c			\
			parsing.c			\
			exit.c				\
			print.c				\
			atol.c				\
			sort.c				\
			wheel_sort.c		\
			main.c)

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
