/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper_c.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 18:57:58 by catalina      #+#    #+#                 */
/*   Updated: 2021/03/11 21:21:36 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_zero_flags_c(t_info info, unsigned char text)
{
	int	i;

	i = 0;
	while (i < info.width - 1)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	ft_putchar_fd(text, 1);
}

void	write_info_mines(unsigned char text, t_info info, int i)
{
	ft_putchar_fd(text, 1);
	i++;
	while (info.width > i)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
}

void	fillchar(unsigned char text, t_info info)
{
	int	i;

	i = 0;
	if (info.width < 1)
		info.width = 1;
	if (info.zero == 1)
		fill_zero_flags_c(info, text);
	else if (info.mines != 0)
		write_info_mines(text, info, i);
	else
	{
		while (info.width - 1 > i)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		ft_putchar_fd(text, 1);
	}
}
