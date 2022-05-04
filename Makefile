NAME	= push_swap

FLAGS	= -Wall -Wextra -Werror -Ofast
INCL	= -I. -I./libft
LIB		= -L./libft -lft

SRCS	= $(addprefix srcs/,	\
			moves.c				\
			moves2.c			\
			moves3.c			\
			parsing.c			\
			sort.c				\
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
