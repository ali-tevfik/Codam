/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_x.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 16:21:14 by catalina      #+#    #+#                 */
/*   Updated: 2021/03/11 21:24:07 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_x(t_info info, va_list data, char karakter)
{
	char	*text;
	int		return_value;

	return_value = 0;
	text = hex_itoa(va_arg(data, unsigned int), karakter);
	if (!text)
		return (-1);
	if (info.prec == -1 && info.width == -1 && text[0] == '\0' && info.coma == 0)
	{
		ft_putchar_fd('0', 1);
		free(text);
		return (1);
	}
	return_value = helper_find_zero_of_space(info, text);
	free(text);
	return (return_value);
}
