# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: catalina <catalina@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/16 22:03:59 by catalina      #+#    #+#                  #
#    Updated: 2021/03/10 17:47:20 by catalina      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT = Libft/libft.a

SRC_PATH = src/

HEADER_FILE	= 	$(SRC_PATH)ft_printf.h

SRC =	ft_printf.c\
		write_sembol.c\
		check_flags.c\
		char.c \
		int.c\
		u_itoa.c\
		u_int.c\
		string.c\
		hex_itoa.c\
		convert_p.c\
		helper_c.c\
		helper_int.c\
		helper_int_2.c\
		convert_x.c



SRC_OBJ 	:= 	$(SRC:%.c=$(SRC_PATH)%.o)

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
