//#include <stdio.h>
#include "ft_push_swap.h"
// #include "Libft/libft.h"
// #include "ft_isdigit_str.c"
// #include "rules_swap.c"
// #include "rules_push.c"
// #include "rules_rotate.c"
// #include "rules_reverse.c"
// #include "check_sort.c"


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
    int i = 0;
    int count;
    t_array fake_array;
    int len;
    int x;

    x = 0;
    len = array.len_array_a;
    fake_array = sort_a(array);
    //printf("uzunluk %d ortadaki eleman %d\n\n",len,array.array_a[len%2]);
    while (array.len_array_a != 1)
    {
         i = 0;
        // int xx=0;
        // printf("\n\nson array\n----------------------------\n");
        // while (xx < array.len_array_a)
        // {
        //     printf("%d\n",array.array_a[xx]);
        //     xx++;
        // }
        //printf("----------------------------\n\n\n");
        while(array.array_a[i] != fake_array.array_a[x] && i < array.len_array_a + 1)
            i++;
        count = i;
       //printf("\narray son %d  count %d len %d,fake sayi %d array(i) %d i = %d len_array_a = %d\n\n",array.array_a[array.len_array_a - 1] ,count,len,fake_array.array_a[x],array.array_a[i],i,array.len_array_a);

       if(count > (len % 2))
       {
            while(fake_array.array_a[x] != array.array_a[0])
                array = rules_reverse_rra(array);
           //printf("if - rotate sayi %d and fake x %d\n",array.array_a[0],fake_array.array_a[x]);
            array = rules_push_pb(array);
           // printf("\n\npsh b %d\n\n",array.array_b[0]);
       }
        else
        {
           while(fake_array.array_a[x] != array.array_a[0])
                array = rules_rotate_ra(array);
           // printf("else - rotate sayi %d and fake x %d\n",array.array_a[0],fake_array.array_a[x]);
            array = rules_push_pb(array);
           // printf("\n\npsh b %d\n\n",array.array_b[0]);
        }

        x++;
    }

    //    int xx=0;
    //     printf("\n\nson array\n----------------------------\n");
    //     while (xx < array.len_array_b)
    //     {
    //         printf("%d\n",array.array_b[xx]);
    //         xx++;
    //     }
    while(array.len_array_b > 0)
    {
        array = rules_push_pa(array);
    }
    return (array);
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
        if(array.array_b[0] < array.array_b[1])
            array = swap_sa(array);
        array = rules_push_pa(array);
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
        if(a.array_a[i] > 2147483647)
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
        //a = sort_smaller(a);
    }
    // int abc = 0;
    // while (a.len_array_a > abc)
    // {
    //     printf("%d\n",a.array_a[abc]);
    //     abc++;
    // }
}

/*
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


//sort b
t_array sort_smaller(t_array array)
{
    int i;
    int x;
    t_result result;
    int abc;
    x = array.len_array_b;
    i = 0;
    while (1 && array.len_array_b > 1)
    {
        abc = 0;
        if (check_bigste(array) == 1)
            array = rules_push_pa(array);
        else if (array.array_b[0] < array.array_b[1])
        {
            array = swap_sb(array);
        }
        else if (array.array_b[array.len_array_b - 1] > array.array_b[array.len_array_b - 2])
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
    array = rules_push_pa(array);

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
    while (1 && array.len_array_b > 1)
    {
        abc = 0;
        if (check_bigste(array) == 1)
            array = rules_push_pa(array);
        else if (array.array_b[0] < array.array_b[1])
        {
            array = swap_sb(array);
        }
        else if (array.array_b[array.len_array_b - 1] > array.array_b[array.len_array_b - 2])
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
    array = rules_push_pa(array);

    return (array);
}
t_array find_pivot(t_array array)
{
    int i = 0;
    int uzunluk_a = array.len_array_a;
    t_array fake_array;
    int len;

    len = array.len_array_a;
    fake_array = sort_a(array);
    //printf("uzunluk %d ortadaki eleman %d\n\n",len,array.array_a[len%2]);
    i = 0;
    while (i < uzunluk_a)
    {
        int abc;
        abc = 0;
        if (fake_array.array_a[len%2] >= array.array_a[0])
        {
            array = rules_push_pb(array);
        }
        else
        {
            array = rules_rotate_ra(array);
        }
        i++;
    }
    return (array);
}
*/
