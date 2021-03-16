/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   u_itoa.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 13:32:23 by adoner        #+#    #+#                 */
/*   Updated: 2021/03/10 17:58:45 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	u_len_find(long n)
{
	long	len;

	len = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	char	*u_convert(long control, long len, long n)
{
	char	*a;

	a = (char *)malloc(len + 1);
	if (!a)
		return (NULL);
	*(a + len) = '\0';
	while (n > 0)
	{
		len--;
		*(a + len) = (n % 10) + '0';
		n /= 10;
	}
	if (control == -1)
	{
		len--;
		*(a + len) = '-';
	}
	return (a);
}

char	*u_itoa(long n)
{
	long	len;
	long	control;

	control = 1;
	if (n == 0)
		return (ft_strdup("0"));
	len = u_len_find(n);
	if (n < 0)
	{
		len++;
		n *= -1;
		control = -1;
	}
	return (u_convert(control, len, n));
}
