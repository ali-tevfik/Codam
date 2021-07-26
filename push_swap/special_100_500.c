/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   special_100_500.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/22 18:12:39 by catalina      #+#    #+#                 */
/*   Updated: 2021/07/26 13:30:07 by catalina      ########   odam.nl         */
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

	posion = 0;
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
	if (posion > array.len_array_b / 2)
	{
		while (array.len_array_b - posion > 0)
		{
			array = rules_reverse_rrb(array);
			posion ++;
		}
	}
	else
	{
		while (posion > 0)
		{
			array = rules_rotate_rb(array);
			posion--;
		}
	}
	x = 0;
	return (array);
}
int find_index(t_array array)
{
	int i;

	i = 0;
	while (array.len_array_b > i)
	{
		if (array.array_a[0] < array.array_b[i] && array.array_a[0] > array.array_b[i + 1])
			return (i);
		i++;
	}
	//printf("\n\nindx bulma func arr[0] = %d i = %d i + 1 = %d index = %d\n",array.array_a[0],array.array_b[x],array.array_b[x + 1], x);

	return (-1);
}

t_array index_find_and_push(t_array array)
{
	int xy;
	int index;

	index = find_index(array);
	//printf("\n\nindex  =  %d a = %d\n\n",index, array.array_a[0]);
	//b_yazdir(array, "index  degismeden once");
	if (index > array.len_array_b / 2)
	{
		while (array.len_array_b - index > 0)
		{
			array = rules_reverse_rrb(array);
			index++;
		}
	//b_yazdir(array, "index sonra if");
	}
	else
	{
		while (index >= 0)
		{
			array = rules_rotate_rb(array);
			index--;
		}
	//	b_yazdir(array, "index sonra else");
	}

	if (array.array_a[0] > array.array_b[0] && array.array_a[0] < array.array_b[array.len_array_b - 1])
			array = rules_push_pb(array);

	//b_yazdir(array, "push sonra");
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
	if (check_sort_a(array).result == 1)
	{
		array = max_digit_up_b(array);
		while (array.len_array_b > 0)
			array = rules_push_pa(array);
		return (array);
	}
	if (max_sayi == array.array_a[0] || min_sayi == array.array_a[0])
	{
		array = max_digit_up_b(array);
		array = rules_push_pb(array);
	}
	else{
		array = index_find_and_push(array);
		}
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
			if (check_sort_a(array).result == 1){
				array = max_digit_up_b(array);
				while (array.len_array_b > 0)
					array = rules_push_pa(array);
			return (array);
			}
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
