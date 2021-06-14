/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules_push.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 17:06:51 by adoner        #+#    #+#                 */
/*   Updated: 2021/06/14 13:04:51 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_array rules_push_pa(t_array arrays)
{
    t_array new_arrays;
    int i;


    i = 1;

    if (arrays.len_array_b <= 0)
        return (arrays);
    arrays.len_array_a++;
    arrays.len_array_b--;
    new_arrays.array_b = (int*)malloc((arrays.len_array_b + 1) * sizeof(int));
    new_arrays.array_a = (int*)malloc((arrays.len_array_a + 1) * sizeof(int));

    while (arrays.len_array_b >= i && arrays.len_array_b > 0)
    {
        new_arrays.array_b[i - 1] = arrays.array_b[i];
        i++;
    }
    i = 0;
    new_arrays.array_a[0] = arrays.array_b[0];
    while (arrays.len_array_a > i + 1)
    {
        new_arrays.array_a[i + 1] = arrays.array_a[i];
        i++;
    }
    free(arrays.array_a);
    if (arrays.array_b > 0)
        free(arrays.array_b);
    new_arrays.len_array_b = arrays.len_array_b;

    new_arrays.len_array_a = arrays.len_array_a;
    return (new_arrays);
}


t_array rules_push_pb(t_array arrays)
{
    t_array new_arrays;
    int i;


    i = 1;
    if (arrays.len_array_a <= 0)
        return (arrays);
    arrays.len_array_a--;
    arrays.len_array_b++;
    new_arrays.array_a = (int*)malloc((arrays.len_array_a + 1) * sizeof(int));
    new_arrays.array_b = (int*)malloc((arrays.len_array_b + 1)* sizeof(int));
    while (arrays.len_array_a >= i)
    {
        new_arrays.array_a[i - 1] = arrays.array_a[i];
        i++;
    }
    i = 0;
    new_arrays.array_b[0] = arrays.array_a[0];
    while (arrays.len_array_b > i + 1)
    {
        new_arrays.array_b[i + 1] = arrays.array_b[i];
        i++;
    }
    if (arrays.len_array_a > 0)
        free(arrays.array_a);
    free(arrays.array_b);
    new_arrays.len_array_a = arrays.len_array_a;
    new_arrays.len_array_b = arrays.len_array_b;
    return (new_arrays);
}
