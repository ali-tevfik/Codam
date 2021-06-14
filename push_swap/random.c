#include <stdio.h>
#include <stdlib.h>

#define ERR_NO_NUM -1
#define ERR_NO_MEM -2

int myRandom (int size) {
    int i, n;
    static int numNums = 0;
    static int *numArr = NULL;

    // Initialize with a specific size.

    if (size >= 0) {
        if (numArr != NULL)
            free (numArr);
        if ((numArr = malloc (sizeof(int) * size)) == NULL)
            return ERR_NO_MEM;
        for (i = 0; i  < size; i++)
            numArr[i] = i;
        numNums = size;
    }

    // Error if no numbers left in pool.

    if (numNums == 0)
       return ERR_NO_NUM;

    // Get random number from pool and remove it (rnd in this
    //   case returns a number between 0 and numNums-1 inclusive).

    n = rand() % numNums;
    i = numArr[n];
    numArr[n] = numArr[numNums-1];
    numNums--;
    if (numNums == 0) {
        free (numArr);
        numArr = 0;
    }

    return i;
}

int main (void) {
    int i;

    i = myRandom (300);
    while (i >= 0) {
        printf ("%3d", i);
        i = myRandom (-1);
    }

    // printf("\n\n");
    // i = myRandom (20);
    // while (i >= 0) {
    //     printf ("%d,", i);
    //     i = myRandom (-1);
    // }
    return 0;
}
