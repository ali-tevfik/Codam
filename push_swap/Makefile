GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m

SRCS	=	check_sort.c\
			ft_isdigit_str.c\
			push_swap.c\
			rules_push.c\
			rules_reverse.c\
			sort.c\
			rules_rotate.c\
			rules_swap.c\
			special_tree.c\
			special_five.c\
			special_100_500.c\
			convert_int.c

OBJS	= $(SRCS:.c=.o)

NAME	= push_swap

GCC		= gcc

FLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

HEADER_FILE = push_swap.h

LIBFT_DIR = libft

LIBFT_LIB = libft.a

all:	$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) bonus -C $(LIBFT_DIR)
	$(GCC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_DIR)/$(LIBFT_LIB)

%.o: %.c $(HEADER_FILE)
	@echo "$(GREEN)Compiling:$(NORMAL)"
	$(GCC) -c $< -o $(<:.c=.o)
	@echo "$(GREEN)Successfully compiled!$(NORMAL)"

clean:
	@echo "$(RED)Removing all object files...$(NORMAL)"
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Succesfully removed all object files!$(NORMAL)"

fclean: clean
	@echo "$(RED)Removing libraries...$(NORMAL)"
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Successfully removed libraries!$(NORMAL)"

re: fclean all

.PHONY:	clean fclean re
