/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 11:26:49 by adoner        #+#    #+#                 */
/*   Updated: 2020/11/16 11:26:51 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				leng;
	unsigned	char	*p;

	leng = 0;
	p = b;
	while (leng < len)
	{
		*(p + leng) = c;
		leng++;
	}
	return (b);
}
