NAME	= push_swap

CFLAGS	= -Wall -Wextra -Werror -Ofast
IFLAG	= -I. -I./libft
LIB		= -L./libft -lft

SRCS_DIR	= srcs
OBJS_DIR	= $(shell mkdir -p objs && printf "objs")

SRCS	=	moves.c				\
			moves2.c			\
			moves3.c			\
			parsing.c			\
			exit.c				\
			print.c				\
			atol.c				\
			sort.c				\
			sort_small.c		\
			wheel_sort.c		\
			main.c

OBJS	= $(SRCS:%.c=$(OBJS_DIR)/%.o)

all :		$(NAME)

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
	gcc $(CFLAGS) $(IFLAG) -c $< -o $@ -g

$(NAME) :	libft.a $(OBJS)
	gcc $(CFLAGS) $(IFLAG) $(LIB) $(OBJS) -o $(NAME) -g

libft.a :
	make -C ./libft

clean :
	make fclean -C ./libft
	rm -rf $(OBJS_DIR)
	rm $(NAME)

fclean :	clean

re :		fclean all

.PHONY :	re all clean fclean
