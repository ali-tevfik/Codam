/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/16 14:03:19 by catalina      #+#    #+#                 */
/*   Updated: 2021/03/11 20:38:22 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_int(t_info info, va_list data)
{
	char	*text;
	int		result;

	text = ft_itoa(va_arg(data, int));
	if (!text)
		return (-1);
	result = helper_find_zero_of_space(info, text);
	free(text);
	return (result);
}
