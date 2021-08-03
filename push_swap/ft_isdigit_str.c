/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit_str.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 15:19:28 by adoner        #+#    #+#                 */
/*   Updated: 2021/08/03 12:29:53 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//check int or char
//if input have char return 0
int	ft_isdigit_str(char **c)
{
	int	i;
	int	x;

	x = 0;
	i = 1;
	while (c[i])
	{
		while (c[i][x])
		{
			if (!(c[i][x] >= '0' && c[i][x] <= '9'))
				return (0);
			x++;
		}
		x = 0;
		i++;
	}
	return (1);
}
