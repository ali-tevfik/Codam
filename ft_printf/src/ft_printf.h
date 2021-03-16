/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 17:33:07 by catalina      #+#    #+#                 */
/*   Updated: 2021/03/11 21:21:43 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"
# include <stdarg.h>

typedef struct s_info
{
	int	mines;
	int	zero;
	int	error;
	int	coma;
	int	width;
	int	prec;
	int	size;
	int	text_len;
	int	prec_is_negative;
}				t_info;
int				ft_printf(const char *format, ...);
int				create_digit(int old_digit, char digit);
int				convert_char(va_list data, t_info info);
t_info			check_flags(const char *str, va_list data);
int				convert_int(t_info info, va_list data);
unsigned int	convert_u_int(t_info info, va_list data);
int				parse_string(va_list data, t_info info);
char			*u_itoa(long n);
int				convert_x(t_info info, va_list data, char karakter);
char			*hex_itoa(unsigned long n, char karakter);
int				write_sembol(t_info info);
int				helper_find_zero_of_space(t_info info, char *text);
void			fillchar(unsigned char text, t_info info);
int				convert_p(t_info info, va_list data);
char			*join_int(t_info info, char *text, char *bigtext,
					int len_width);
char			*fill_int(int len_width, int len_prec, char *text, t_info info);
int				find_len_width_int(int len_width, t_info info, char *text);
char			*fill_zero_flags(int len_width, int len_prec, char *text,
					t_info info);

char			*create_malloc_0(t_info info, char *text, int len_prec,
					int len_width);
char			*join_zero_text(char *text, char *bigtext, int len_prec,
					t_info info);

char			*fill_zero_txt(char *bigtext, char *text, int len_prec, int i);

char			*fill_space_end(char *tmp, int len_width);
#endif
