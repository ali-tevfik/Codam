/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_swap.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 17:33:07 by catalina      #+#    #+#                 */
/*   Updated: 2021/08/02 14:30:58 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"
# include <stdarg.h>

typedef struct s_array
{
	int		*array_a;
	int		*array_b;
	int		len_array_a;
	int		len_array_b;
	int		check_malloc;
}			t_array;

typedef struct s_result
{
	int		where;
	int		result;
}			t_result;

int			main(int argc, char **argv);
int			*find_max_min_digit(t_array array);
int			ft_isdigit_str(char **c);
int			find_index(t_array array);
t_array		max_digit_up_b(t_array array);
int			find_posion(t_array array);
t_array		speical_big_digit(t_array array, int how_many);
t_array		swap_sa(t_array array);
t_array		swap_sb(t_array array);
t_array		swap_ss(t_array array);
t_array		rules_push_pb(t_array big_array);
t_array		rules_push_pa(t_array big_array);
t_array		rules_rotate_ra(t_array array);
t_array		rules_rotate_rb(t_array array);
t_array		rules_rotate_rr(t_array array);
t_array		rules_reverse_rrr(t_array array);
t_array		rules_reverse_rra(t_array array);
t_array		rules_reverse_rrb(t_array array);
t_result	check_sort_a(t_array array);
t_result	check_sort_b(t_array array);
t_array		digit_3_speaciel(t_array array);
t_array		digit_5_speaciel(t_array array);
int			*convert_int(char **argv, int len);
t_array		speical_big_digit(t_array array, int how_many);
t_array		check_malloc(t_array array);
t_array		free_array (t_array array);
#endif
