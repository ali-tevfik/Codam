/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_p.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 18:40:44 by catalina      #+#    #+#                 */
/*   Updated: 2021/03/10 17:54:41 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_big_text(t_info info)
{
	char	*big_text;

	if (info.width > 0 && info.coma == 0)
		big_text = ft_strdup("0x0");
	else if (info.width == -1 && info.coma == 0 && info.prec == -1)
		big_text = ft_strdup("0x0");
	else if (info.prec == -1 && info.coma == 1 && info.width == -2)
		big_text = ft_strdup("0x0");
	else
		big_text = ft_strdup("0x");
	return (big_text);
}

int	convert_p(t_info info, va_list data)
{
	char	*text;
	char	*big_text;
	int		len;

	text = hex_itoa(va_arg(data, unsigned long), 'x');
	if (!text)
		return (-1);
	if (text[0] == '0' && text[1] == '\0')
		big_text = fill_big_text(info);
	else
		big_text = ft_strjoin("0x", text);
	free(text);
	if (!big_text)
		return (-1);
	len = helper_find_zero_of_space(info, big_text);
	free(big_text);
	return (len);
}
