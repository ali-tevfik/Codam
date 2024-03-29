/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_malloc.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/28 13:16:05 by catalina      #+#    #+#                 */
/*   Updated: 2021/08/03 12:11:59 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// if malloc crash i call this func and free array_a and array_b
t_array	free_array(t_array array)
{
	if (array.array_a && array.len_array_a > 0)
		free(array.array_a);
	if (array.array_b && array.len_array_b > 0)
		free(array.array_b);
	array.check_malloc = -1;
	return (array);
}

//i check malloc crash or not
t_array	check_malloc(t_array array)
{
	array.check_malloc = 0;
	if (!array.array_a && !array.array_b)
	{
		array.check_malloc = -1;
		return (array);
	}
	if (!array.array_a && array.len_array_a > 0)
	{
		array.check_malloc = -1;
		if (array.array_b && array.len_array_b > 0)
			free (array.array_b);
	}
	if (!array.array_b && array.len_array_b > 0)
	{
		array.check_malloc = -1;
		if (array.array_a && array.len_array_a > 0)
			free(array.array_a);
	}
	return (array);
}
