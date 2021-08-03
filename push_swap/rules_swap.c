/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules_swap.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 16:38:29 by adoner        #+#    #+#                 */
/*   Updated: 2021/08/03 11:57:41 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	*fill_swap_array(int *array, int len)
{
	int	i;
	int	*new_array;

	i = 2;
	new_array = (int *)malloc((len + 1) * sizeof(new_array));
	if (!new_array)
		return (NULL);
	new_array[0] = array[1];
	new_array[1] = array[0];
	while (i <= len)
	{
		new_array[i] = array[i];
		i++;
	}
	free(array);
	return (new_array);
}

t_array	swap_sa(t_array array)
{
	int	i;
	int	len;

	array = check_malloc(array);
	if (array.check_malloc == -1)
		return (array);
	ft_putendl_fd("sa", 1);
	len = array.len_array_a;
	i = 2;
	array.array_a = fill_swap_array(array.array_a, len);
	if (!array.array_a)
	{
		array = free_array(array);
		return (array);
	}
	return (array);
}

t_array	swap_sb(t_array array)
{
	int	len;

	array = check_malloc(array);
	if (array.check_malloc == -1)
		return (array);
	ft_putendl_fd("sb", 1);
	len = 0;
	if (array.array_b)
		len = array.len_array_b;
	if (len == 0 || len == 1)
		return (array);
	array.array_b = fill_swap_array(array.array_b, len);
	if (!array.array_b)
	{
		array = free_array(array);
		return (array);
	}
	return (array);
}

t_array	swap_ss(t_array array)
{
	array = swap_sa(array);
	array = swap_sb(array);
	return (array);
}
