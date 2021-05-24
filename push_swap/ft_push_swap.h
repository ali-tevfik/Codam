/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_swap.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 17:33:07 by catalina      #+#    #+#                 */
/*   Updated: 2021/05/24 19:20:10 by adoner        ########   odam.nl         */
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

int main(int argc, char **argv);
int ft_isdigit_str(char **c);
t_array swap_sa(t_array array);
t_array swap_sb(t_array array);
t_array swap_ss(t_array array);
t_array rules_push_pa(t_array big_array);
#endif