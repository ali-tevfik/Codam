/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 23:57:12 by catalina      #+#    #+#                 */
/*   Updated: 2021/05/25 00:38:42 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//if return 0 , thats didn't good work!
int check_sort_a(t_array array)
{
	int i;

	i = 0;
	while (i < array.len_array_a - 1)
	{
		if (array.array_a[i] > array.array_a[i + 1])
			return (0);
		i++;
	}
	return (1);

}
int check_sort_b(t_array array)
{
	int i;

	i = 0;
	while (i < array.len_array_b - 1)
	{
		if (array.array_b[i] > array.array_b[i + 1])
			return (0);
		i++;
	}
	return (1);

}
