/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/22 18:10:07 by catalina      #+#    #+#                 */
/*   Updated: 2021/08/03 16:28:09 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//input convert int and fill array_a
int	*convert_int(char **argv, int len)
{
	int		*array;
	int		x;
	int		y;
	long	digit;

	x = 1;
	y = 0;
	array = (int *) malloc((len + 1) * sizeof(array));
	if (!array)
		return (NULL);
	while (argv[x])
	{
		digit = ft_atoi(argv[x]);
		if (digit > 2147483647 || digit <= -2147483648)
		{
			free(array);
			error_text();
			return (NULL);
		}
		else
			array[y] = ft_atoi(argv[x]);
		y++;
		x++;
	}
	return (array);
}
