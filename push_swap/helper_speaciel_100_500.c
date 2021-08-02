/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper_speaciel_100_500.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/02 13:41:05 by catalina      #+#    #+#                 */
/*   Updated: 2021/08/02 14:30:48 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_posion(t_array array)
{
	int	max_digit;
	int	posion;
	int	x;

	posion = 0;
	x = 0;
	max_digit = array.array_b[0];
	while (array.len_array_b > x)
	{
		if (max_digit < array.array_b[x])
		{
			max_digit = array.array_b[x];
			posion = x;
		}
		x++;
	}
	return (posion);
}

int	*find_max_min_digit(t_array array)
{
	int	*max_min_arr;
	int	x;

	max_min_arr = (int *)malloc(3 * sizeof(max_min_arr));
	if (!max_min_arr)
		return (NULL);
	max_min_arr[0] = array.array_a[0];
	max_min_arr[1] = array.array_a[0];
	x = 0;
	while (array.len_array_b > x)
	{
		if (array.array_b[x] > max_min_arr[0])
			max_min_arr[0] = array.array_b[x];
		else if (array.array_b[x] < max_min_arr[1])
			max_min_arr[1] = array.array_b[x];
		x++;
	}
	return (max_min_arr);
}

t_array	max_digit_up_b(t_array array)
{
	int	posion;

	posion = find_posion(array);
	if (posion > array.len_array_b / 2)
	{
		while (array.len_array_b - posion > 0)
		{
			array = rules_reverse_rrb(array);
			posion ++;
		}
	}
	else
	{
		while (posion > 0)
		{
			array = rules_rotate_rb(array);
			posion--;
		}
	}
	return (array);
}

int	find_index(t_array array)
{
	int	i;

	i = 0;
	while (array.len_array_b > i)
	{
		if (array.array_a[0] <= array.array_b[i]
			&& array.array_a[0] >= array.array_b[i + 1])
			return (i);
		i++;
	}
	return (-1);
}
