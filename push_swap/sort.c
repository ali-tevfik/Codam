/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/26 17:36:06 by catalina      #+#    #+#                 */
/*   Updated: 2021/07/26 17:36:08 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	*helper_sort(int arr[], int length)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

t_array	sort_a(t_array array)
{
	int	arr[array.len_array_a + 1];
	int	x;
	int	*new_arr;
	t_array	fake_array;

	x = 0;
	while (array.len_array_a >= x)
	{
		arr[x] = array.array_a[x];
		x++;
	}
	new_arr = helper_sort(arr, array.len_array_a);
	x = 0;
	fake_array.array_a = (int *)malloc(sizeof(fake_array.array_a) * (array.len_array_a + 1));
	while (x <= array.len_array_a)
	{
		fake_array.array_a[x] = new_arr[x + 1];
		x++;
	}
	return (fake_array);
}
