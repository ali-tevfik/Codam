/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_swap.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 17:33:07 by catalina      #+#    #+#                 */
/*   Updated: 2021/05/25 17:33:42 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"
# include <stdarg.h>

typedef struct  s_array
{
    int*        array_a;
    int*        array_b;
    int         len_array_a;
    int         len_array_b;
}               t_array;

typedef struct s_result
{
    int         where;
    int         result;
}               t_result;

int main(int argc, char **argv);
int ft_isdigit_str(char **c);
t_array swap_sa(t_array array);
t_array swap_sb(t_array array);
t_array swap_ss(t_array array);
t_array rules_push_pb(t_array big_array);
t_array rules_push_pa(t_array big_array);
t_array rules_rotate_ra(t_array array);
t_array rules_rotate_rb(t_array array);
t_array rules_rotate_rr(t_array array);
t_array rules_reverse_rrr(t_array array);
t_array rules_reverse_rra(t_array array);
t_array rules_reverse_rrb(t_array array);
t_result check_sort_a(t_array array);
t_result check_sort_b(t_array array);
#endif
