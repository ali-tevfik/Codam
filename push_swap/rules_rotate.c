/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules_rotate.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 23:20:11 by catalina      #+#    #+#                 */
/*   Updated: 2021/06/24 15:29:17 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_array rules_rotate_ra(t_array array)
{
	int* new_array;
	int i;
    ft_putendl_fd("ra",1);
	if (array.len_array_a <= 0)
		return (array);
	i = 0;
	new_array = (int*)malloc((array.len_array_a + 1) * sizeof(int));

	new_array[array.len_array_a - 1] = array.array_a[0];
	while (i < array.len_array_a - 1)
	{
		new_array[i] = array.array_a[i + 1];
		i++;
	}
	free(array.array_a);
	array.array_a = new_array;
	return (array);
}

t_array rules_rotate_rb(t_array array)
{
	int* new_array;
	int i;

    ft_putendl_fd("rb",1);
	if (array.len_array_b <= 0)
		return (array);
	i = 0;
	new_array = (int*)malloc((array.len_array_b + 1) * sizeof(int));
	new_array[array.len_array_b - 1] = array.array_b[0];
	while (i < array.len_array_b - 1)
	{
		new_array[i] = array.array_b[i + 1];
		i++;
	}
	if (array.array_b != 0)
		free(array.array_b);
	array.array_b = new_array;
	return (array);
}

t_array rules_rotate_rr(t_array array)
{
	array = rules_rotate_ra(array);
	array = rules_rotate_rb(array);
	return (array);
}
