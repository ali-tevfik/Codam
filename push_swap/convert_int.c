/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/22 18:10:07 by catalina      #+#    #+#                 */
/*   Updated: 2021/07/26 15:02:23 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	*convert_int(char **argv, int len)
{
	int	*array;
	int	x;
	int	y;

	x = 1;
	y = 0;
	array = (int *) malloc(len * sizeof(int));
	if (!array)
		return (NULL);
	while (argv[x])
	{
		array[y] = ft_atoi(argv[x]);
		y++;
		x++;
	}
	return (array);
}
