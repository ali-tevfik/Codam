/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules_swap.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 16:38:29 by adoner        #+#    #+#                 */
/*   Updated: 2021/05/24 19:42:09 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_array swap_sa(t_array array)
{
    int* new_array;
    int i;
    int len;

    len = array.len_array_a;
    i = 2;
    new_array = (int*)malloc(len * sizeof(int));
    new_array[0] = array.array_a[1];
    new_array[1] = array.array_a[0];
    while (i <= len)
    {
        new_array[i] = array.array_a[i];
        i++;
    }
    free(array.array_a);
    array.array_a = new_array;
    return (array);
}

t_array swap_sb(t_array array)
{
    int* new_array;
    int i;
    int len;

    len = 0;
    if (array.array_b)
        len = array.len_array_b;
    if (len == 0 || len == 1)
        return (array);
    i = 2;
    printf("len %d", len);
    new_array = (int*)malloc(len * sizeof(int));
    new_array[0] = array.array_b[1];
    new_array[1] = array.array_b[0];
    while (i <= len)
    {
        new_array[i] = array.array_b[i];
        i++;
    }
    free(array.array_b);
    array.array_b = new_array;
    return (array);
}

t_array swap_ss(t_array array)
{
    array =swap_sa(array);
    array =swap_sb(array);
    return (array);
}