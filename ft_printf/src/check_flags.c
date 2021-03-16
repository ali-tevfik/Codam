/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 14:43:13 by catalina      #+#    #+#                 */
/*   Updated: 2021/03/11 21:20:46 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info	fill_flags(void)
{
	t_info	info;

	info.coma = 0;
	info.prec = -1;
	info.zero = 0;
	info.error = 0;
	info.width = -1;
	info.mines = 0;
	info.prec_is_negative = 0;
	return (info);
}

t_info	fill_width_or_prec(t_info info, char str)
{
	if (info.coma != 0)
	{
		info.prec = create_digit(info.prec, str);
		if (info.mines != 0 && info.prec < 0)
			info.prec = -1;
		else if (info.prec < 0)
		{
			info.prec = info.width;
			info.width = -2;
		}
		info.prec_is_negative = 2;
	}
	else
		info.width = create_digit(info.width, str);
	return (info);
}

t_info	fill_width_or_prec_with_star(t_info info, va_list data)
{
	if (info.coma == 0)
	{
		info.width = va_arg(data, int);
		if (info.width < 0)
		{
			info.mines += 1;
			info.width *= -1;
		}
	}
	else
	{
		info.prec = va_arg(data, int);
		if (info.mines != 0 && info.prec < 0)
			info.prec = -1;
		else if (info.prec < 0)
		{
			info.prec = info.width;
			info.width = -2;
		}
		info.prec_is_negative = 2;
	}
	return (info);
}

t_info	check_mines(t_info info)
{
	if (info.width == -1 && info.coma == 0)
		info.mines += 1;
	else
	{
		info.error = -1;
		return (info);
	}
	return (info);
}

t_info	check_flags(const char *str, va_list data)
{
	t_info	info;
	int		i;

	i = 0;
	info = fill_flags();
	while (str[i] && info.error != -1)
	{
		info.size = i;
		if (str[i] == '.')
			info.coma += 1;
		else if (str[i] == '*')
			info = fill_width_or_prec_with_star(info, data);
		else if (str[i] == '-')
			info = check_mines(info);
		else if (str[i] == '0' && i == 0)
			info.zero = 1;
		else if (ft_isdigit(str[i]))
			info = fill_width_or_prec(info, str[i]);
		else if (str[i] == ' ' && i == 0)
			ft_putchar_fd(' ', 1);
		else
			return (info);
		i++;
	}
	return (info);
}
