#include "ft_push_swap.h"
t_array sort_a(t_array array)
{
    int arr[array.len_array_a + 1];
    int x;
    x = 0;
    t_array fake_array;
    while (array.len_array_a >= x)
    {
        arr[x] = array.array_a[x];
        x++;
    }

    int temp = 0;

    //Calculate length of array arr
    int length = sizeof(arr) / sizeof(arr[0]);

    //Sort the array in ascending order
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    x = 0;
    fake_array.array_a = (int *)malloc(sizeof(fake_array.array_a) * (array.len_array_a + 1));
    while (x <= array.len_array_a)
    {
        fake_array.array_a[x] = arr[x + 1];
        x++;
    }

    // int xx = 0;
    // while (array.len_array_a > xx)
    // {
    // 	printf("\n%d =  %d\n",xx,fake_array.array_a[xx]);
    // 	xx++;
    // }

    return (fake_array);
}
