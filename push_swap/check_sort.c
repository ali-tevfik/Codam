/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 23:57:12 by catalina      #+#    #+#                 */
/*   Updated: 2021/05/25 17:32:27 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//if return 0 , thats didn't good work!
t_result check_sort_a(t_array array)
{
	int i;
	t_result result;

	result.result = 0;
	i = 0;
	while (i < array.len_array_a - 1)
	{
		result.where = i;
		if (array.array_a[i] > array.array_a[i + 1])
			return (result);
		i++;
	}
	result.result = 1;
	return (result);

}
t_result check_sort_b(t_array array)
{
	int i;
	t_result result;

	result.result = 0;
	i = 0;
	while (i < array.len_array_b - 1)
	{
		result.where = i;
		if (array.array_b[i] < array.array_b[i + 1])
			return (result);
		i++;
	}

	result.result = 1;
	return (result);

}
