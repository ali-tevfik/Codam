/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 00:06:01 by catalina      #+#    #+#                 */
/*   Updated: 2021/03/13 13:09:09 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	create_digit(int old_digit, char digit)
{
	if (old_digit == -1)
		return (digit - '0');
	old_digit *= 10;
	old_digit += ft_atoi(&digit);
	return (old_digit);
}

int	parse(char symbol, va_list data, t_info info)
{
	int	return_value;

	return_value = 0;
	if (symbol == 'd' || symbol == 'i')
		return_value = convert_int(info, data);
	else if (symbol == 's')
		return_value = parse_string(data, info);
	else if (symbol == 'c')
		return_value = convert_char(data, info);
	else if (symbol == 'u')
		return_value = convert_u_int(info, data);
	else if (symbol == 'x' || symbol == 'X')
		return_value = convert_x(info, data, symbol);
	else if (symbol == '%')
		return_value = write_sembol(info);
	else if (symbol == 'p')
		return_value = convert_p(info, data);
	else
		return (-1);
	return (return_value);
}

int	read_data(const char *format, va_list data, int i, int return_value)
{
	t_info	info;
	int		result;

	while (format[i])
	{
		if (format[i] == '%')
		{
			info = check_flags(format + i + 1, data);
			result = parse(format[i + info.size + 1], data, info);
			i += info.size;
			i++;
			if (result == -1)
				return (-1);
			return_value += result;
		}
		else
		{
			write(1, (format + i), 1);
			return_value++;
		}
		i++;
	}
	return (return_value);
}

int	ft_printf(const char *format, ...)
{
	va_list	data;
	int		i;
	int		return_value;

	i = 0;
	va_start(data, format);
	return_value = 0;
	return_value = read_data(format, data, i, return_value);
	va_end(data);
	return (return_value);
}
