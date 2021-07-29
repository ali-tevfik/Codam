/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules_rotate.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 23:20:11 by catalina      #+#    #+#                 */
/*   Updated: 2021/07/29 18:53:05 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	*fill_rotate(int *array, int len)
{
	int	*new_array;
	int	i;

	i = 0;
	new_array = (int *)malloc((len + 1) * sizeof(new_array));
	if (!new_array)
		return (NULL);
	new_array[len - 1] = array[0];
	while (i < len - 1)
	{
		new_array[i] = array[i + 1];
		i++;
	}
	free(array);
	return (new_array);
}

t_array	rules_rotate_ra(t_array array)
{
	array = check_malloc(array);
	if (array.check_malloc == -1)
		return (array);
	ft_putendl_fd("ra", 1);
	if (array.len_array_a <= 0)
		return (array);
	array.array_a = fill_rotate(array.array_a, array.len_array_a);
	if (!array.array_a)
	{
		array = free_array(array);
		return (array);
	}
	return (array);
}

t_array	rules_rotate_rb(t_array array)
{
	array = check_malloc(array);
	if (array.check_malloc == -1)
		return (array);
	ft_putendl_fd("rb", 1);
	if (array.len_array_b <= 0)
		return (array);
	array.array_b = fill_rotate(array.array_b, array.len_array_b);
	if (!array.array_b)
	{
		array = free_array(array);
		return (array);
	}
	return (array);
}

t_array	rules_rotate_rr(t_array array)
{
	array = rules_rotate_ra(array);
	array = rules_rotate_rb(array);
	return (array);
}
