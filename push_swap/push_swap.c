/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/22 18:15:08 by catalina      #+#    #+#                 */
/*   Updated: 2021/07/26 13:35:02 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "ft_push_swap.h"

t_array find_pivot(t_array array)
{
    int i = 0;
    int count;
    t_array fake_array;
    int len;
    int x;

    x = 0;
    len = array.len_array_a;
    fake_array = sort_a(array);
    while (array.len_array_a != 1)
    {
        i = 0;
        while (array.array_a[i] != fake_array.array_a[x] && i < array.len_array_a + 1)
            i++;
        count = i;

        if (count > (len % 2))
        {
            while (fake_array.array_a[x] != array.array_a[0])
                array = rules_reverse_rra(array);
            array = rules_push_pb(array);
        }
        else
        {
            while (fake_array.array_a[x] != array.array_a[0])
                array = rules_rotate_ra(array);
            array = rules_push_pb(array);
        }

        x++;
    }

    while (array.len_array_b > 0)
    {
        array = rules_push_pa(array);
    }
    return (array);
}

int main(int argc, char **argv)
{
    t_array a;
    int i = 0;

    if (!ft_isdigit_str(argv))
    {
        ft_putendl_fd("ERROR", 1);
        return (0);
    }

    a.array_a = convert_int(argv, argc - 1);
    a.len_array_a = argc - 1;
    while (a.array_a[i])
    {
        if (a.array_a[i] > 2147483647)
        {
            ft_putendl_fd("ERROR", 1);
            return (0);
        }
        i++;
    }
    i = 0;
    a.len_array_b = 0;
    while (a.len_array_a > i)
    {
        if (a.array_a[i] > 2147483647 || a.array_a[i] <= -2147483648)
        {
            ft_putendl_fd("ERROR", 1);
            return (0);
        }
        i++;
    }
    i = 0;

    if (check_sort_a(a).result == 1)
        return (0);
    if (argc == 4)
        a = digit_3_speaciel(a);
    else if (argc == 6)
    {
        while (i < 2)
        {
            a = digit_5_speaciel(a);
            i++;
        }
    }
    else if (argc == 101)
        a = speical_big_digit(a, 5);
    else if (argc == 501)
        a = speical_big_digit(a, 10);
    else
         a = find_pivot(a);
    // int abc = 0;
    // while (a.len_array_a > abc)
    // {
    //     printf("%d\n",a.array_a[abc]);
    //     abc++;
    // }
    // printf("len a = %d len b = %d\n",a.len_array_a,a.len_array_b);
}
