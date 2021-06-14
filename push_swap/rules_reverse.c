/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules_reverse.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 23:20:11 by catalina      #+#    #+#                 */
/*   Updated: 2021/06/14 13:05:04 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_array rules_reverse_rra(t_array array)
{
	int* new_array;
	int i;

	if (array.len_array_a <= 0)
		return (array);
	i = 1;
	new_array = (int*)malloc((array.len_array_a + 1) * sizeof(int));
	new_array[0] = array.array_a[array.len_array_a - 1];
	while (i < array.len_array_a)
	{
		new_array[i] = array.array_a[i - 1];
		i++;
	}
	free(array.array_a);
	array.array_a = new_array;
	int abc = 0;
	return (array);
}

t_array rules_reverse_rrb(t_array array)
{
	int* new_array;
	int i;

	if (array.len_array_b <= 0)
		return (array);
	i = 1;
	new_array = (int*)malloc((array.len_array_b) * sizeof(int));
	new_array[0] = array.array_b[array.len_array_b - 1];
	while (i < array.len_array_b)
	{
		new_array[i] = array.array_b[i - 1];
		i++;
	}
	free(array.array_b);
	array.array_b = new_array;
	return (array);
}

t_array rules_reverse_rrr(t_array array)
{
	array = rules_rotate_ra(array);
	array = rules_rotate_rb(array);
	return (array);
}
