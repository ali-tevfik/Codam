/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   special_100_500.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/22 18:12:39 by catalina      #+#    #+#                 */
/*   Updated: 2021/08/03 12:27:27 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_array	index_find_and_push(t_array array)
{
	int	xy;
	int	index;

	index = find_index(array);
	if (index > array.len_array_b / 2)
	{
		while (array.len_array_b - index > 0)
		{
			array = rules_reverse_rrb(array);
			index++;
		}
	}
	else
	{
		while (index >= 0)
		{
			array = rules_rotate_rb(array);
			index--;
		}
	}
	if (array.array_a[0] >= array.array_b[0]
		&& array.array_a[0] <= array.array_b[array.len_array_b - 1])
		array = rules_push_pb(array);
	return (array);
}

//i'm looking array_b max en min digit.
//if my digit bigger than arrayb or smaller than array b, i only push b
// else i'm looking index
t_array	sort_b(t_array array)
{
	int	*max_min_arr;
	int	xy;

	max_min_arr = find_max_min_digit(array);
	xy = 0;
	if (check_sort_a(array).result == 1)
	{
		array = max_digit_up_b(array);
		while (array.len_array_b > 0)
			array = rules_push_pa(array);
		return (array);
	}
	if (max_min_arr[0] == array.array_a[0]
		|| max_min_arr[1] == array.array_a[0])
	{
		array = max_digit_up_b(array);
		array = rules_push_pb(array);
	}
	else
		array = index_find_and_push(array);
	free(max_min_arr);
	return (array);
}

int	find_chunk_max(t_array array, int how_many)
{
	int	i;
	int	max;
	int	min;

	max = array.array_a[0];
	min = array.array_a[0];
	i = 0;
	while (i < array.len_array_a)
	{
		if (max < array.array_a[i])
			max = array.array_a[i];
		else if (min > array.array_a[i])
			min = array.array_a[i];
		i++;
	}
	return ((max - min) / how_many);
}

// if array_b len smaller than 2 i only push_pb
//if array_b length bigger than 2 first sort array_b
t_array	edit_chunk(t_array array, int max_digit_chunk, int count, int i)
{
	while (i < array.len_array_a)
	{
		if (check_sort_a(array).result == 1)
		{
			array = max_digit_up_b(array);
			while (array.len_array_b > 0)
				array = rules_push_pa(array);
			return (array);
		}
		if (max_digit_chunk * count + count * 1 > array.array_a[0])
		{
			if (array.len_array_b >= 2)
				array = sort_b(array);
			else
				array = rules_push_pb(array);
		}
		else
		{
			array = rules_rotate_ra(array);
			i++;
		}
	}
	return (array);
}

// first finds max number in first chunk.
//	for each chunk it pushes the numbers in the correct order to array_b
t_array	speical_big_digit(t_array array, int how_many)
{
	int		count;
	int		len;
	int		max_digit_chunk;

	max_digit_chunk = find_chunk_max(array, how_many);
	len = array.len_array_a;
	count = 1;
	while (count - 1 <= how_many)
	{
		array = edit_chunk(array, max_digit_chunk, count, 0);
		count++;
	}
	array = max_digit_up_b(array);
	while (array.len_array_b > 0)
		array = rules_push_pa(array);
	return (array);
}
