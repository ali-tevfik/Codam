//#include <stdio.h>
#include "ft_push_swap.h"
// #include "Libft/libft.h"
// #include "ft_isdigit_str.c"
// #include "rules_swap.c"
// #include "rules_push.c"
// #include "rules_rotate.c"
// #include "rules_reverse.c"
// #include "check_sort.c"
t_array sort_smaller(t_array array);

int *convert_int(char **argv, int len)
{
    int *array;
    int x;
    int y;

    x = 1;
    y = 0;
    array = (int *)malloc(len * sizeof(int));
    if (!array)
        return (NULL);
    while (argv[x])
    {
        array[y] = ft_atoi(argv[x]);
        y++;
        x++;
    }
    return (array);
}

t_array find_pivot(t_array array)
{
    int i = 1;
    int mod_sayisi = array.len_array_a / 5;
    int x;
    int len_a;
    int a = 0;
    int sonuc2;
    int sonuc;
    int count_b;
    t_array fake_array;
    int sayi; 

    if (array.len_array_a == 499)
        sayi = 11;
    else
        sayi = 5;
    count_b = 0;
    fake_array = sort(array);
    x = 0;
   while (mod_sayisi >= x)
   {
       if (x == 0)
            sonuc2 = 0;
        else
            sonuc2 = (x -1) * sayi;
       sonuc = x * sayi; 
       len_a = array.len_array_a;
       a = 0;
       while(a <= len_a)
       {
           //printf("\n\nsuanki mod %d\nmod sayisi = %d  \nx.i = %d \n(x-1).i = %d \nfake_array\n\tmax = %d\n\tmin= %d\narray_a[0] %d\nindex sayisi %d\n ",x,mod_sayisi,sonuc,sonuc2,fake_array.array_a[sonuc],fake_array.array_a[sonuc2],array.array_a[0],a);
           if ((fake_array.array_a[sonuc2] < array.array_a[0]) && fake_array.array_a[sonuc] >= array.array_a[0]){
            //printf("\n\n\n\n pusb %d \n\n\n\n\n",array.array_a[0]);
            count_b++;
            array = rules_push_pb(array);    
            // printf("-----------------------------------------------------\n");
            }
           else
                array = rules_reverse_rra(array);
            a++;
                
       }
    array = sort_smaller(array);
    int len_b = array.len_array_b;
    while (len_b-- >= 0)
        array = rules_push_pa(array);
       
       x++;
    }  
    int len_b = array.len_array_b;
    return (array);
}

int find_smallest(t_array array)
{
    int i;

    i = 0;
    while (i < array.len_array_a)
    {
        if (array.array_a[0] > array.array_a[i])
            return (0);
        i++;
    }
    return (1);
}

int en_buyuk_sayi_bul_a(t_array array)
{
    int buyuk_sayi;
    int x;
    int buyuk_index;

    buyuk_index = 0;
    x = 0;
    buyuk_sayi = array.array_a[0];
    while (x < array.len_array_a)
    {
        if (buyuk_sayi < array.array_a[x])
        {
            buyuk_sayi = array.array_a[x];
            buyuk_index = x;
        }
        x++;
    }
    return (buyuk_index);
}

//sort a
t_array sort_bigger(t_array array)
{
    int i;
    int x;
    t_result result;
    int abc;
    x = array.len_array_a;
    i = 0;
    while (array.len_array_a > 1)
    {
        if (find_smallest(array) == 1)
            array = rules_push_pb(array);
        else if (array.array_a[0] > array.array_a[1])
        {
            array = swap_sa(array);
        }
        else if (array.array_a[0] > array.array_a[array.len_array_a - 1])
        {
            array = rules_rotate_ra(array);
        }

        else if (check_sort_a(array).result == 0)
        {
            int en_buyuk = en_buyuk_sayi_bul_a(array);
            int n = 0;
            if (en_buyuk > array.len_array_a / 2)
            {
                while (n <= en_buyuk)
                {
                    array = rules_reverse_rra(array);
                    n++;
                }
            }

            else
            {
                while (n < en_buyuk)
                {
                    array = rules_rotate_ra(array);
                    n++;
                }
            }
        }

        else
            break;
    }

    array = rules_push_pa(array);
    t_result ak = check_sort_b(array);
    return (array);
}
int check_bigste(t_array array)
{
    int i = 0;
    while (array.len_array_b > i && array.len_array_b != 1)
    {
        if (array.array_b[0] < array.array_b[i])
            return (0);
        i++;
    }
    return (1);
}

//3 lu ozel
t_array digit_3_speaciel(t_array array)
{
    int i;
    int x;
    t_result result;
    int abc;
    x = array.len_array_a;
    i = 0;
    while (1 && array.len_array_a > 1)
    {
        if (array.array_a[0] > array.array_a[array.len_array_a - 1])
        {
            array = rules_rotate_ra(array);
        }
        else if (array.array_a[array.len_array_a - 1] < array.array_a[array.len_array_a - 2])
        {
            array = rules_reverse_rra(array);
        }
        else if (array.array_a[0] > array.array_a[1])
        {
            array = swap_sa(array);
        }
        else if (check_sort_a(array).result == 1)
            break;
    }
    return (array);
}

//sort b
t_array sort_smaller(t_array array)
{
    int i;
    int x;
    t_result result;
    int abc;
    x = array.len_array_b;
    i = 0;
    while (1 && array.len_array_b >= 1)
    {
        abc = 0;
        if (array.array_b[array.len_array_b - 1] > array.array_b[array.len_array_b - 2])
        {
            array = rules_reverse_rrb(array);
        }
        else if (array.array_b[0] < array.array_b[array.len_array_b - 1])
        {
            array = rules_rotate_rb(array);
        }
        else if ((result = check_sort_b(array)).result != 1)
        {
            abc = 0;
            while (abc < result.where)
            {
                array = rules_rotate_rb(array);
                abc++;
            }
        }
        else
            break;
    }
   

    return (array);
}

int where_small_digit(t_array array)
{
    int small_digit;
    int i;
    int count;

    count = 0;
    i = 0;
    small_digit = array.array_a[0];
    while (array.len_array_a > i)
    {
        //printf("\ndigit is %d\n",array.array_a[i]);
        if (small_digit > array.array_a[i])
        {
        //    printf("\nsmall digit is %d\n",array.array_a[i]);
            small_digit = array.array_a[i];
            count = i;
        }
        i++;
    }
    //printf("\n count is %d digit is %d small digit is %d\n",count,array.array_a[count],small_digit);
    return (count);
}
t_array digit_5_speaciel(t_array array)
{
    int small_digit_count;
    int i;

    i = 0;
    small_digit_count = where_small_digit(array);

    if (small_digit_count > 3)
    {
        while (5 - small_digit_count > 0)
        {
            array = rules_reverse_rra(array);
            small_digit_count++;
        }
    }
    else
    {
        while (i < small_digit_count)
        {
            array = rules_rotate_ra(array);
            i++;
        }
    }
    //printf("gitdi\n");
    array = rules_push_pb(array);
    if (array.len_array_a == 3)
    {
        array = digit_3_speaciel(array);
        array = sort_smaller(array);
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
    a.len_array_b = 0;

    if (check_sort_a(a).result == 1)
        return (0);
    if (argc == 4)
        a = digit_3_speaciel(a);
    else if (argc == 6)
    {
        while (i  < 2)
        {
             a = digit_5_speaciel(a);
             i++;
        }

    }

    else
    {
        a = find_pivot(a);
        // a = sort_bigger(a);
        // a = sort_smaller(a);
    }

    int abc = 0;
    while (a.len_array_a > abc)
    {
        printf("%d\n",a.array_a[abc]);
        abc++;
    }
}
