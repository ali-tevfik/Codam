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
    int *array;
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
    int uzunluk_a = array.len_array_a;
    while (i < array.len_array_a)
    {
        toplam  += array.array_a[i];
        i++;

    }
    int ortalama = toplam / array.len_array_a;
   // ////////printf("ortalama = %d  toplam sayi = %d\n",ortalama,array.len_array_a);
    i = 0;
    while (i < uzunluk_a)
    {
        int abc;
        abc = 0;
    //    while (abc < array.len_array_a)
    //        ////////printf("son hali hali %d\n",array.array_a[abc++]);
    //    ////////printf("\n\n");
        if (ortalama >= array.array_a[0]){
              //  ////////printf("girdi a\n");
            array = rules_push_pb(array);
           // ////////printf("push b %d\n",array.array_b[0]);
          //  ////////printf("\narray b %d\n",array.array_b[0]);
          }
        else{

            //     ////////printf("girdi b\n");
           //  ////////printf("push a %d\n",array.array_a[0]);
    //              while (abc < array.len_array_a)
    //        ////////printf("reverse oncesi %d\n",array.array_a[abc++]);
    //    ////////printf("----------------------\n\n");
           array = rules_rotate_ra(array);

            }
         // ////////printf("total a = %d\ntotal B = %d\nsayi = %d ",array.len_array_a,array.len_array_b,i);

        i++;
    //////////printf("\n\n");
    }
   // ////////printf("\n");

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
{   int i;
    int x;
    t_result result;
    int abc;
    x = array.len_array_a;
    i = 0;
    while (1 && array.len_array_a > 1)
    {
        for (int ac = 0; ac < array.len_array_a; ac++)
        {
            ////////printf("sort a son hali %d\n",array.array_a[ac]);
        }
        if (find_smallest(array) == 1)
            array = rules_push_pb(array);
        else if (array.array_a[0] > array.array_a[1]){
            array = swap_sa(array);
        }
        else if (array.array_a[array.len_array_a - 1] < array.array_a[array.len_array_a - 2])
        {
            array = rules_reverse_rra(array);
        }
        else if (array.array_a[0] > array.array_a[array.len_array_a - 1]){
            array = rules_rotate_ra(array);
        }
        else if (check_sort_a(array).result == 0)
        {
           int en_buyuk =  en_buyuk_sayi_bul_a(array);
           int n = 0;
           if (en_buyuk > array.len_array_a / 2)
           {
                while (n < en_buyuk){
                    array = rules_reverse_rra(array);
                    n++;}
           }
        else
        {
               while (n < en_buyuk){
                    array = rules_rotate_ra(array);
                    n++;}
           }
        }


        else
            break;


        // else if ((result = check_sort_a(array)).result != 1)
        // {
        //     abc = 0;
        //     //////////printf("sa calisti");
        //    // //////////printf("\nresult is %d\n\n",result.where);
        //     while (abc < result.where)
        //     {
        //         array = rules_rotate_ra(array);
        //         abc++;
        //     }

        // }

       }
      //  //////////printf("x = %d i = %d\n\n",x,i);

        array = rules_push_pa(array);

        t_result ak = check_sort_b(array);
        ////////////printf("sonuc %d\n",ak.result);
         abc = 0;
    //     while (abc < array.len_array_a)
    //        //////////printf("B\n\nson hali hali %d\n",array.array_a[abc++]);
    //     //////////printf("\n\n");
    // //////////printf("a bitti \n\n--------------------------------\n\n\n");

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
        ////////////printf("LEN %d\n\n",array.len_array_b);
        //while (abc < array.len_array_b)
          //  //////////printf("son hali hali %d\n",array.array_b[abc++]);
        ////////////printf("\n\n");
        if (check_bigste(array) == 1)
            array = rules_push_pa(array);
        else if (array.array_b[0] < array.array_b[1]){
            array = swap_sb(array);
            // //////////printf("swap sb = %d %d\n",array.array_b[0],array.array_b[1]);
          //  //////////printf("sb calisti\n");
         }
        else if (array.array_b[array.len_array_b - 1] > array.array_b[array.len_array_b - 2])
        {
            array = rules_reverse_rrb(array);
          //  //////////printf("reverse rrb calisti\n");
           //  //////////printf("reverse rb = %d %d\n",array.array_b[array.len_array_b - 1],array.array_b[array.len_array_b - 2]);
           }
        else if (array.array_b[0] < array.array_b[array.len_array_b - 1]){
            array = rules_rotate_rb(array);
        //    //////////printf("rotate rb calisti\n");
            ////////////printf("rules rb = %d %d\n",array.array_b[0],array.array_b[array.len_array_b-1]);
            }
        else if ((result = check_sort_b(array)).result != 1)
        {
            abc = 0;
           // //////////printf("\nresult is %d\n\n",result.where);
            while (abc < result.where)
            {
                array = rules_rotate_rb(array);
                abc++;
            }

        }
        else
            break;
       }
        //////////printf("x = %d i = %d\n\n",x,i);

        array = rules_push_pa(array);
        // t_result ak = check_sort_b(array);
        // ////////printf("sonuc %d\n",ak.result);
        // abc = 0;
        // while (abc < array.len_array_b)
        //    ////////printf("A\n\nson hali hali %d\n",array.array_b[abc++]);
        // ////////printf("\n\n");
   // ////////printf("B BTIIT\n\n--------------------------------\n\n");
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
   // ////////printf("\na = %d %d %d %d %d %d ",a.array_a[0],a.array_a[1],a.array_a[2],a.array_b[0],a.array_a[2],a.array_a[3]);
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
    // ////////printf("last and result is %d\n", result);
    // while (i < a.len_array_a)
    //     ////////printf(" %d \t",a.array_a[i++]);
    // ////////printf("\n\n");



    // a = rules_push_pa(a);
    // i = 0;
    // ////////printf("push pa\n");
    // while (i < a.len_array_a)
    //     ////////printf(" %d \t",a.array_a[i++]);
    // ////////printf("\n\n");

    //   a = rules_push_pa(a);
    // i = 0;
    // ////////printf("push pa\n");
    // while (i < a.len_array_a)
    //     ////////printf(" %d \t",a.array_a[i++]);
    // ////////printf("\n\n");
    //  i = 0;
    // ////////printf("b list\n");
    // while (i < a.len_array_b)
    //     ////////printf(" %d \t",a.array_b[i++]);
    // ////////printf("\n\n");

    // a = swap_sa(a);
    //   i = 0;

    // ////////printf("swap sa\n");
    // while (i < a.len_array_a)
    //     ////////printf("%d \t",a.array_a[i++]);
    // ////////printf("\n\n");

    // a = swap_sb(a);
    //   i = 0;
    //   ////////printf("swap sb\n");
    // while (i < a.len_array_b)
    //     ////////printf("  %d \t",a.array_b[i++]);
    // ////////printf("\n\n");

    //  a = swap_ss(a);
    //   i = 0;
    //   ////////printf("asfad sa\n");
    // while (i < a.len_array_a)
    //     ////////printf("  %d \t",a.array_a[i++]);
    // ////////printf("\n\n");
    //  i = 0;
    //   ////////printf("asfad sb\n");
    // while (i < a.len_array_b)
    //     ////////printf("  %d \t",a.array_b[i++]);
    // ////////printf("\n\n");



}
