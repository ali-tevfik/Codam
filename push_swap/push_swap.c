#include <stdio.h>
#include "ft_push_swap.h"
#include "Libft/libft.h"
#include "ft_isdigit_str.c"
#include "rules_swap.c"
#include "rules_push.c"

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
    int     len;
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
    printf("first\n");
    while (i < a.len_array_a)
        printf(" %d \t",a.array_a[i++]);
    printf("\n\n");
    
    a = rules_push_pa(a);
    i = 0;
    printf("push pa\n");
    while (i < a.len_array_a)
        printf(" %d \t",a.array_a[i++]);
    printf("\n\n");
    
      a = rules_push_pa(a);
    i = 0;
    printf("push pa\n");
    while (i < a.len_array_a)
        printf(" %d \t",a.array_a[i++]);
    printf("\n\n");
     i = 0;
    printf("b list\n");
    while (i < a.len_array_b)
        printf(" %d \t",a.array_b[i++]);
    printf("\n\n");

    a = swap_sa(a);
      i = 0;

    printf("swap sa\n");
    while (i < a.len_array_a)
        printf("%d \t",a.array_a[i++]);
    printf("\n\n");

    a = swap_sb(a);
      i = 0;
      printf("swap sb\n");
    while (i < a.len_array_b)
        printf("  %d \t",a.array_b[i++]);
    printf("\n\n");

     a = swap_ss(a);
      i = 0;
      printf("asfad sa\n");
    while (i < a.len_array_a)
        printf("  %d \t",a.array_a[i++]);
    printf("\n\n");
     i = 0;
      printf("asfad sb\n");
    while (i < a.len_array_b)
        printf("  %d \t",a.array_b[i++]);
    printf("\n\n");

}