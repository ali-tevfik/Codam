/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normal_digit_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/26 18:41:45 by catalina      #+#    #+#                 */
/*   Updated: 2021/07/26 18:53:00 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
t_array	push_pb_helper(t_array array, t_array fake_array, int x, int i)
{
	int	len;

	len = array.len_array_a;
	if (i > (len % 2))
		while (fake_array.array_a[x] != array.array_a[0])
			array = rules_reverse_rra(array);
	else
		while (fake_array.array_a[x] != array.array_a[0])
			array = rules_rotate_ra(array);
	array = rules_push_pb(array);
	return (array);
}

t_array	find_pivot(t_array array)
{
	int		i;
	t_array	fake_array;
	int		x;

	x = 0;
	fake_array = sort_a(array);
	while (array.len_array_a != 1)
	{
		i = 0;
		while (array.array_a[i] != fake_array.array_a[x]
			&& i < array.len_array_a + 1)
			i++;
		array = push_pb_helper(array, fake_array, x, i);
		x++;
	}
	while (array.len_array_b > 0)
		array = rules_push_pa(array);
	array = rules_reverse_rra(array);
	return (array);
}
