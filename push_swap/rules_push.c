/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules_push.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 17:06:51 by adoner        #+#    #+#                 */
/*   Updated: 2021/07/29 19:01:37 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_array	rules_push_pa(t_array array)
{
	t_array	new_arrays;
	int		i;

	array = check_malloc(array);
	if (array.check_malloc == -1)
		return (array);
	ft_putendl_fd("pa", 1);
	i = 1;
	if (array.len_array_b <= 0)
		return (array);
	array.len_array_a++;
	array.len_array_b--;
	new_arrays.array_b = (int*)malloc((array.len_array_b + 1) * sizeof(new_arrays));
	new_arrays.array_a = (int*)malloc((array.len_array_a + 1) * sizeof(new_arrays));
	if (!new_arrays.array_a || !new_arrays.array_b)
	{
		array = free_array(array);
		return (array);
	}
	while (array.len_array_b >= i && array.len_array_b > 0)
	{
		new_arrays.array_b[i - 1] = array.array_b[i];
		i++;
	}
	i = 0;
	new_arrays.array_a[0] = array.array_b[0];
	while (array.len_array_a > i + 1)
	{
		new_arrays.array_a[i + 1] = array.array_a[i];
		i++;
	}
	free(array.array_a);
	if (array.array_b)
		free(array.array_b);
	new_arrays.len_array_b = array.len_array_b;
	new_arrays.len_array_a = array.len_array_a;
	return (new_arrays);
}

t_array	rules_push_pb(t_array array)
{
	t_array	new_arrays;
	int		i;

	array = check_malloc(array);
	if (array.check_malloc == -1)
		return (array);
	ft_putendl_fd("pb", 1);
	i = 1;
	if (array.len_array_a <= 0)
		return (array);
	array.len_array_a--;
	array.len_array_b++;
	new_arrays.array_a = (int*) malloc ((array.len_array_a + 1) * sizeof(new_arrays));
	new_arrays.array_b = (int*) malloc ((array.len_array_b + 1) * sizeof(new_arrays));
	if (!new_arrays.array_a || !new_arrays.array_b)
	{
		array = free_array(array);
		return (array);
	}
	while (array.len_array_a >= i)
	{
		new_arrays.array_a[i - 1] = array.array_a[i];
		i++;
	}
	i = 0;
	new_arrays.array_b[0] = array.array_a[0];
	while (array.len_array_b > i + 1)
	{
		new_arrays.array_b[i + 1] = array.array_b[i];
		i++;
	}
	if (array.array_a)
		free(array.array_a);
	free(array.array_b);
	new_arrays.len_array_a = array.len_array_a;
	new_arrays.len_array_b = array.len_array_b;
	return (new_arrays);
}
