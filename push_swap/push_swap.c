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


    i = 0;
    int toplam = 0;
    printf("first\n");
    while (i < a.len_array_a)
    {
        toplam  += a.array_a[i];
        printf(" %d \t",a.array_a[i++]);

    }
    int ortalama = toplam / a.len_array_a;
    i = 0;
    while (i < a.len_array_a)
    {
        if (ortalama >= a.array_a[0])
            a = rules_push_pb(a);
        else
           a = rules_rotate_ra(a);
        i++;
    }

    int aa =0;
    int a_ort = 0;
    while(aa < a.len_array_a)
        a_ort += a.array_a[aa++];
    a_ort /= a.len_array_a;
    aa = 0;
    while (1)
    {
        if (a.array_a[aa] > a_ort)
            a = rules_rotate_ra(a);
        else if (a.array_a[aa] > a.array_a[aa + 1])
            a = swap_sa(a);
        else
            break;

    }

     aa =0;
    int b_ort = 0;
    while(aa < a.len_array_b)
        b_ort += a.array_b[aa++];
    b_ort /= a.len_array_b;
    aa = 0;
    while (1)
    {
        if (a.array_b[0] < b_ort)
            a = rules_reverse_rrb(a);
        else if (a.array_b[aa] < a.array_b[aa + 1])
        {
            a =rules_rotate_rb(a);
            a = swap_sb(a);
            a =rules_reverse_rrb(a);
        }
        else if (a.array_b[0] < a.array_b[a.len_array_b])
            a = rules_rotate_rb(a);
        else if (a.len_array_b > aa)
            aa++;
        else
            break;

    }
    int bc = 0;
    while(a.len_array_b + 1 >=bc)
    {
        a = rules_push_pa(a);
        bc++;
    }

    printf("\n\nORTALAMA = %d\n\n",ortalama);
    //printf("b = %d %d %d\n\n",a.array_b[0],a.array_b[1],a.array_b[2]);
    printf("a = %d %d %d %d %d %d ",a.array_a[0],a.array_a[1],a.array_a[2],a.array_a[3],a.array_a[4],a.array_a[5]);
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
