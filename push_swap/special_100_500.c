/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   special_100_500.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/22 18:12:39 by catalina      #+#    #+#                 */
/*   Updated: 2021/07/22 18:51:38 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void b_yazdir(t_array array,char *txt)
{
	int x = 0;
	printf ("\n======================%s\n",txt);
	while (x < array.len_array_b)
	{
		printf("%d\n",array.array_b[x]);
		x++;
	}

	printf ("======================");
}

t_array max_digit_up_b(t_array array)
{
	int x;
	int max_digit;
	int posion;

	x = 0;
	max_digit = array.array_b[0];
	while (array.len_array_b > x)
	{
		if (max_digit < array.array_b[x])
		{
			max_digit = array.array_b[x];
			posion = x;
		}
		x++;
	}
	while (posion > 0)
	{
		array = rules_rotate_rb(array);
		posion--;
	}
	x = 0;
	return (array);
}

t_array index_find_and_push(t_array array)
{
	int xy;

	xy = 0;
	while (array.len_array_b > xy)
	{
		if (array.array_a[0] > array.array_b[0] && array.array_a[0] < array.array_b[array.len_array_b - 1])
		{
			array = rules_push_pb(array);
			break;
		}
		else
			array = rules_rotate_rb(array);
	}
	return (array);
}

// i'm looking array_b max en min digit. if my digit bigger than arrayb or smaller than array b, i only push b
// else i'm looking index
t_array sort_b(t_array array)
{
	int max_sayi;
	int min_sayi;
	int xy = 0;

	max_sayi = array.array_a[0];
	min_sayi = array.array_a[0];
	xy = 0;
	while (array.len_array_b > xy)
	{
		if (array.array_b[xy] > max_sayi)
			max_sayi = array.array_b[xy];
		else if (array.array_b[xy] < min_sayi)
			min_sayi = array.array_b[xy];
		xy++;
	}
	xy = 0;
	if (max_sayi == array.array_a[0] || min_sayi == array.array_a[0])
	{
		array = max_digit_up_b(array);
		array = rules_push_pb(array);
		b_yazdir(array,"max min");
	}
	else{
		array = index_find_and_push(array);
		b_yazdir(array,"index");}
	return (array);
}

// b de iki den fazla eleman varsa yerlestirme yapiyorum
//yoksa direk pushb
t_array speical_big_digit(t_array array, int how_many)
{
	t_array fake_array;
	int count;
	int i;
	int len;

	len = array.len_array_a;
	count = 1;
	fake_array = sort_a(array);
	while (count <= how_many)
	{
		i = 0;
		while (i < array.len_array_a)
		{
			if (fake_array.array_a[len / how_many * count] > array.array_a[0])
			{

				if (array.len_array_b >= 2)
					array = sort_b(array);
				else
					array = rules_push_pb(array);
			}
			else
			{
				array = rules_rotate_ra(array);
				i++;
			}
		}
		count++;
	}
	array = max_digit_up_b(array);
	while (array.len_array_b > 0)
		array = rules_push_pa(array);
	return (array);
}
