NAME	= push_swap

CFLAGS	= -Wall -Wextra -Werror -Ofast
IFLAG	= -I. -I./libft
LIB		= -L./libft -lft

SRCS_DIR	= srcs
OBJS_DIR	= objs

SRCS	=	moves.c				\
			moves2.c			\
			moves3.c			\
			parsing.c			\
			exit.c				\
			print.c				\
			atol.c				\
			sort.c				\
			wheel_sort.c		\
			main.c

OBJS	= $(SRCS:%.c=$(OBJS_DIR)/%.o)

all :		$(NAME)

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
	gcc $(CFLAGS) $(IFLAG) -c $< -o $@

$(NAME) :	libft.a $(OBJS)
	gcc $(FLAGS) $(IFLAG) $(LIB) $(OBJS) -o $(NAME)

libft.a :
	make -C ./libft

clean :
	make fclean -C ./libft
	rm -rf $(OBJS_DIR)/*.o
	rm $(NAME)

fclean :	clean

re :		fclean all

.PHONY :	re all clean fclean
