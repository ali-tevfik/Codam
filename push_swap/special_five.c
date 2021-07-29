/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   special_five.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/22 18:00:02 by catalina      #+#    #+#                 */
/*   Updated: 2021/07/28 13:35:50 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	where_small_digit(t_array array)
{
	int	small_digit;
	int	i;
	int	count;

	count = 0;
	i = 0;
	small_digit = array.array_a[0];
	while (array.len_array_a > i)
	{
		if (small_digit > array.array_a[i])
		{
			small_digit = array.array_a[i];
			count = i;
		}
		i++;
	}
	return (count);
}

t_array	edit_five(t_array array)
{
	array = digit_3_speaciel(array);
	if (array.array_b[0] < array.array_b[1])
		array = swap_sa(array);
	array = rules_push_pa(array);
	array = rules_push_pa(array);
	return (array);
}

t_array	digit_5_speaciel(t_array array)
{
	int	small_digit_count;
	int	i;

	i = 0;
	small_digit_count = where_small_digit(array);
	if (small_digit_count > 3)
	{
		while (5 - small_digit_count > 0 && array.array_a)
		{
			array = rules_reverse_rra(array);
			small_digit_count++;
		}
	}
	else
	{
		while (i < small_digit_count && array.array_a)
		{
			array = rules_rotate_ra(array);
			i++;
		}
	}
	array = rules_push_pb(array);
	if (array.len_array_a == 3 && array.array_a)
		array = edit_five(array);
	return (array);
}
