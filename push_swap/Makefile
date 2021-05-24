# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: catalina <catalina@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/16 22:03:59 by catalina      #+#    #+#                  #
#    Updated: 2021/05/25 00:07:27 by catalina      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap.a

LIBFT = Libft/libft.a


HEADER_FILE	= 	$(SRC_PATH)ft_printf.h

SRC =	push_swap.c/
		rules_push.c/
		rules_reverse.c/
		rules_rotate.c/
		rules_swap.c/
		ft_isdigit_str.c/
		check_sort.c



SRC_OBJ 	:= 	$(SRC:%.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(SRC_OBJ)
	cp $< $@
	ar cr $@ $(SRC_OBJ)

%.o: %.c $(HEADER_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make bonus -C libft

clean:
	make fclean -C libft
	rm -f $(SRC_OBJ)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

