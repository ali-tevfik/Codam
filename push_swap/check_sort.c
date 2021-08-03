/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 23:57:12 by catalina      #+#    #+#                 */
/*   Updated: 2021/08/03 12:10:44 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// if array_a[0] > array_b(all items) return = 1
int	check_a_bigger_b(t_array array)
{
	int	max_sayi;
	int	xy;

	xy = 0;
	max_sayi = array.array_a[0];
	xy = 0;
	while (array.len_array_b > xy)
	{
		if (array.array_b[xy] > max_sayi)
			return (0);
		xy++;
	}
	return (1);
}

//check sort array_a and array_b
// if array_a and array_b sort return 1
t_result	check_sort_a(t_array array)
{
	int			i;
	t_result	result;

	result.result = 0;
	i = 0;
	while (i < array.len_array_a - 1)
	{
		result.where = i;
		if (array.array_a[i] > array.array_a[i + 1])
			return (result);
		i++;
	}
	if (check_a_bigger_b(array) == 1)
		result.result = 1;
	else
		result.result = 0;
	return (result);
}
