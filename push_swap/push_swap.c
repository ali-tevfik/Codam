/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/22 18:15:08 by catalina      #+#    #+#                 */
/*   Updated: 2021/08/03 16:30:24 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	error_text(void)
{
	ft_putendl_fd("ERROR", 1);
	return (0);
}

//fill array_a with input
t_array	fill_array_a(t_array array, char **argv, int argc)
{
	array.array_a = convert_int(argv, argc - 1);
	array.len_array_a = argc - 1;
	array.len_array_b = 0;
	return (array);
}

t_array	sort_start(t_array array, int argc)
{
	int	i;

	i = 0;
	if (argc <= 4)
		array = digit_3_speaciel(array);
	else if (argc == 6)
	{
		while (i < 2)
		{
			array = digit_5_speaciel(array);
			i++;
		}
	}
	else if (argc == 101)
		array = speical_big_digit(array, 5);
	else if (argc == 501)
		array = speical_big_digit(array, 10);
	else
		array = speical_big_digit(array, 2);
	return (array);
}

int	check_dublicate(t_array array)
{
	int	x;
	int	i;

	i = 0;
	while (array.len_array_a > i)
	{
		x = i - 1;
		while (x >= 0)
		{
			if (array.array_a[x] == array.array_a[i])
			{
				array = free_array(array);
				error_text();
				return (0);
			}
			x--;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_array	array;

	i = 0;
	if (!ft_isdigit_str(argv))
		return (error_text());
	array = fill_array_a(array, argv, argc);
	if (!array.array_a)
		return (0);
	if (check_dublicate(array) == 0)
		return (0);
	if (check_sort_a(array).result != 1)
		array = sort_start(array, argc);
	if (array.array_a)
		free(array.array_a);
	if (array.array_b)
		free(array.array_b);
	return (0);
}
