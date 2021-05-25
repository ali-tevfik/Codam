#include <stdio.h>
#include "ft_push_swap.h"
#include "Libft/libft.h"
#include "ft_isdigit_str.c"
#include "rules_swap.c"
#include "rules_push.c"
#include "rules_rotate.c"
#include "rules_reverse.c"
#include "check_sort.c"

int* convert_int(char **argv, int len)
{
    int* array;
    int x;
    int y;

    x = 1;
    y = 0;
    array = (int*)malloc(len * sizeof(int));
    if (!array)
        return (NULL);
    while(argv[x])
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
    int toplam = 0;
    while (i < array.len_array_a)
    {
        toplam  += array.array_a[i];
        i++;

    }
    int ortalama = toplam / array.len_array_a;
    printf("ortalama = %d  toplam sayi = %d\n",ortalama,array.len_array_a);
    i = 0;
    while (i < array.len_array_a)
    {

        if (ortalama >= array.array_a[0]){
            array = rules_push_pb(array);
            printf("push b %d\n",array.array_b[0]);
            i--;
          //  printf("\narray b %d\n",array.array_b[0]);
          }
        else{
            printf("push a %d\n",array.array_a[0]);
           array = rules_rotate_ra(array);

            }
        i++;
    }
    printf("\n");

    return (array);
}

//sort a
t_array sort_bigger(t_array array)
{
    t_result result;
    int abc = 0;
    if (check_sort_a(array).result == 1)
        return (array);
    while (1)
    {
        abc = 0;
        while (abc < array.len_array_a)
            printf("son hali hali %d\n",array.array_a[abc++]);
        printf("\n\n");
        if (array.array_a[0] > array.array_a[1]){
            array = swap_sa(array);
            printf("swap sa = %d %d\n",array.array_a[0],array.array_a[1]);
            }
         else if (array.array_a[array.len_array_a - 1] < array.array_a[array.len_array_a - 2]){
            array = rules_reverse_rra(array);
            printf("reverse ra = %d %d\n",array.array_a[array.len_array_a - 1],array.array_a[array.len_array_a - 2]);
            }
        else if (array.array_a[0] > array.array_a[array.len_array_a - 1]){
            array = rules_rotate_ra(array);
            printf("rules ra = %d %d\n",array.array_a[0],array.array_a[array.len_array_a-1]);
            }
          else if ((result = check_sort_a(array)).result != 1)
        {
            abc = 0;
            printf("\nresult is %d\n\n",result.where);
            while (abc < result.where)
            {
                array = rules_rotate_ra(array);
                abc++;
            }
            
        }
        else
            break;
       }
       printf("--------------------------------\n");
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
    while (1)
    {
         abc = 0;
        while (abc < array.len_array_b)
            printf("son hali hali %d\n",array.array_b[abc++]);
        printf("\n\n");
        if (array.array_b[0] < array.array_b[1]){
            array = swap_sb(array);
             printf("swap sb = %d %d\n",array.array_b[0],array.array_b[1]);}
        else if (array.array_b[array.len_array_b - 1] > array.array_b[array.len_array_b - 2])
        {
            array = rules_reverse_rrb(array);
             printf("reverse rb = %d %d\n",array.array_b[array.len_array_b - 1],array.array_b[array.len_array_b - 2]);}
        else if (array.array_b[0] < array.array_b[array.len_array_b - 1]){
            array = rules_rotate_rb(array);

            printf("rules rb = %d %d\n",array.array_b[0],array.array_b[array.len_array_b-1]);
            }
        else if ((result = check_sort_b(array)).result != 1)
        {
            abc = 0;
            printf("\nresult is %d\n\n",result.where);
            while (abc < result.where)
            {
                array = rules_rotate_rb(array);
                abc++;
            }
            
        }
        else 
            break;
       }
        printf("x = %d i = %d\n\n",x,i);
        while (x > i)
        {
            array = rules_push_pa(array);
            i++;
        }

    printf("--------------------------------\n");
    return (array);
}

int main(int argc, char **argv)
{
    t_array a;
    int i =0;


    if (!ft_isdigit_str(argv))
    {
        ft_putendl_fd("ERROR", 1);
        return (0);
    }

    a.array_a = convert_int(argv, argc - 1);
    a.len_array_a = argc - 1;
    a.len_array_b = 0;



  
    a = find_pivot(a);
    a = sort_bigger(a);
    a = sort_smaller(a);
    int abc = 0;
    while (abc < argc - 1)
    {
        printf("a = %d\n",a.array_a[abc]);
        abc++;
    }
   // printf("\na = %d %d %d %d %d %d ",a.array_a[0],a.array_a[1],a.array_a[2],a.array_b[0],a.array_a[2],a.array_a[3]);
    // a = swap_sa(a);
    // a = rules_push_pb(a);
    // a = rules_push_pb(a);
    // a = rules_push_pb(a);
    // a = rules_rotate_ra(a);
    // a = rules_rotate_rb(a);
    // a = rules_reverse_rra(a);
    // a = rules_reverse_rrb(a);
    // a = swap_sa(a);
    // a = rules_push_pa(a);
    // a = rules_push_pa(a);
    // a = rules_push_pa(a);


    // int result = check_sort(a);

    // i = 0;
    // printf("last and result is %d\n", result);
    // while (i < a.len_array_a)
    //     printf(" %d \t",a.array_a[i++]);
    // printf("\n\n");



    // a = rules_push_pa(a);
    // i = 0;
    // printf("push pa\n");
    // while (i < a.len_array_a)
    //     printf(" %d \t",a.array_a[i++]);
    // printf("\n\n");

    //   a = rules_push_pa(a);
    // i = 0;
    // printf("push pa\n");
    // while (i < a.len_array_a)
    //     printf(" %d \t",a.array_a[i++]);
    // printf("\n\n");
    //  i = 0;
    // printf("b list\n");
    // while (i < a.len_array_b)
    //     printf(" %d \t",a.array_b[i++]);
    // printf("\n\n");

    // a = swap_sa(a);
    //   i = 0;

    // printf("swap sa\n");
    // while (i < a.len_array_a)
    //     printf("%d \t",a.array_a[i++]);
    // printf("\n\n");

    // a = swap_sb(a);
    //   i = 0;
    //   printf("swap sb\n");
    // while (i < a.len_array_b)
    //     printf("  %d \t",a.array_b[i++]);
    // printf("\n\n");

    //  a = swap_ss(a);
    //   i = 0;
    //   printf("asfad sa\n");
    // while (i < a.len_array_a)
    //     printf("  %d \t",a.array_a[i++]);
    // printf("\n\n");
    //  i = 0;
    //   printf("asfad sb\n");
    // while (i < a.len_array_b)
    //     printf("  %d \t",a.array_b[i++]);
    // printf("\n\n");



}
