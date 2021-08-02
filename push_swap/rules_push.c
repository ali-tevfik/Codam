/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules_push.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 17:06:51 by adoner        #+#    #+#                 */
/*   Updated: 2021/08/02 13:31:12 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	*fill_push_send(int *send_array, int *received_array, int len)
{
	int	*new_array_send;
	int	i;

	i = 0;
	new_array_send = (int *)malloc((len + 1) * sizeof(new_array_send));
	if (!new_array_send)
		return (NULL);
	while (len > i + 1)
	{
		new_array_send[i + 1] = send_array[i];
		i++;
	}
	new_array_send[0] = received_array[0];
	if (send_array)
		free(send_array);
	return (new_array_send);
}

int	*fill_push_recevied(int *received_array, int len)
{
	int	*new_received_arr;
	int	i;

	i = 1;
	new_received_arr = (int *)malloc((len + 1) * sizeof(new_received_arr));
	if (!new_received_arr)
		return (NULL);
	while (len >= i && len > 0)
	{
		new_received_arr[i - 1] = received_array[i];
		i++;
	}
	if (received_array)
		free(received_array);
	return (new_received_arr);
}

t_array	rules_push_pa(t_array array)
{
	array = check_malloc(array);
	if (array.check_malloc == -1)
		return (array);
	ft_putendl_fd("pa", 1);
	if (array.len_array_b <= 0)
		return (array);
	array.len_array_a++;
	array.len_array_b--;
	array.array_a = fill_push_send(array.array_a, array.array_b,
			array.len_array_a);
	array.array_b = fill_push_recevied(array.array_b, array.len_array_b);
	if (!array.array_b || !array.array_a)
		return (free_array(array));
	return (array);
}

t_array	rules_push_pb(t_array array)
{
	array = check_malloc(array);
	if (array.check_malloc == -1)
		return (array);
	ft_putendl_fd("pb", 1);
	if (array.len_array_a <= 0)
		return (array);
	array.len_array_a--;
	array.len_array_b++;
	array.array_b = fill_push_send(array.array_b, array.array_a,
			array.len_array_b);
	array.array_a = fill_push_recevied(array.array_a, array.len_array_a);
	if (!array.array_b || !array.array_a)
		return (free_array(array));
	return (array);
}
