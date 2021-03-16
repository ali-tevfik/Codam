/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex_itoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 13:32:23 by adoner        #+#    #+#                 */
/*   Updated: 2021/03/11 21:17:12 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	hex_len_find(unsigned long n)
{
	unsigned long	len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static	char	*hex_convert(unsigned long len, unsigned long n, char karakter)
{
	char	*a;

	a = (char *)malloc(len + 1);
	if (!a)
		return (NULL);
	*(a + len) = '\0';
	while (n > 0)
	{
		len--;
		if ((n % 16) < 10)
			*(a + len) = (n % 16) + '0';
		else
		{
			if (karakter == 'x')
				*(a + len) = (n % 16) + 'a' - 10 ;
			else
				*(a + len) = (n % 16) + 'A' - 10 ;
		}
		n /= 16;
	}
	return (a);
}

char	*hex_itoa(unsigned long n, char karakter)
{
	unsigned long	len;

	len = hex_len_find(n);
	if (n == 0)
		return (ft_strdup("0"));
	return (hex_convert(len, n, karakter));
}
