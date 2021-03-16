/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_sembol.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 01:29:20 by catalina      #+#    #+#                 */
/*   Updated: 2021/03/11 21:14:26 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_sembol(t_info info)
{
	unsigned char	text;

	text = '%';
	if (info.coma == 0 && info.width == 0)
	{
		ft_putchar_fd(text, 1);
		return (1);
	}
	fillchar(text, info);
	if (info.width > 1)
		return (info.width);
	return (1);
}
