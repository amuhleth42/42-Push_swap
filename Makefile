NAME	= push_swap

CFLAGS	= -Wall -Wextra -Werror -Ofast
IFLAG	= -I. -I./libft
LIB		= -L./libft -lft

SRCS_DIR	= srcs
OBJS_DIR	= $(shell mkdir -p objs && printf "objs")
OBJS_B_DIR	= $(shell mkdir -p objs_bonus && printf "objs_bonus")

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
			wheel_sort2.c		\
			wheel_sort3.c		\
			main.c

SRCS_B	=	moves.c				\
			moves2.c			\
			moves3.c			\
			parsing.c			\
			exit.c				\
			print.c				\
			atol.c				\
			sort.c				\
			sort_small.c		\
			wheel_sort.c		\
			wheel_sort2.c		\
			wheel_sort3.c		\
			checker.c

OBJS	= $(SRCS:%.c=$(OBJS_DIR)/%.o)

OBJS_B	= $(SRCS_B:%.c=$(OBJS_B_DIR)/%.o)

all :		$(NAME)

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
	gcc $(CFLAGS) $(IFLAG) -c $< -o $@ -g

$(NAME) :	libft.a $(OBJS)
	gcc $(CFLAGS) $(IFLAG) $(LIB) $(OBJS) -o $(NAME) -g

libft.a :
	make -C ./libft

$(OBJS_B_DIR)/%.o :	bonus/%.c
	gcc $(CFLAGS) $(IFLAG) -c $< -o $@ -g

bonus : all $(OBJS_B)
	gcc $(CFLAGS) $(IFLAG) $(LIB) $(OBJS_B) -o checker

clean :
	make fclean -C ./libft
	rm -rf $(OBJS_DIR)
	rm $(NAME)
	rm -rf $(OBJS_B_DIR)
	rm checker

fclean :	clean

re :		fclean all

.PHONY :	re all clean fclean bonus
