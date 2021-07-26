/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   special_tree.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/22 17:54:57 by catalina      #+#    #+#                 */
/*   Updated: 2021/07/26 16:45:23 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_array	digit_3_speaciel(t_array array)
{
	int		i;
	int		abc;
	t_result	result;

	i = 0;
	while (1 && array.len_array_a > 1)
	{
		if (array.array_a[0] > array.array_a[array.len_array_a - 1])
			array = rules_rotate_ra(array);
		else if (array.array_a[array.len_array_a - 1] < array.array_a[array.len_array_a - 2])
			array = rules_reverse_rra(array);
		else if (array.array_a[0] > array.array_a[1])
			array = swap_sa(array);
		else if (check_sort_a(array).result == 1)
			break ;
	}
	return (array);
}
