
/*
 Input = an integer.
 Convert the integer into binary and print the maximum no. of consecutive 1s in the binary no.

 input :
 6

 output :
 2

 explanation : 6 = 110(int binary), so the max no. of 1s in 110 is 2.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter a no.: ");
    scanf("%d", &n);
    if (n == 0)
    {
        printf("%d", n);
    }

    int i = 0;
    int *a = malloc(1024 * sizeof(int));
    int rem;

    while (n)
    {
        rem = n % 2;
        n = n / 2;
        a[i] = rem;
        i++;
    }

    int max = 0, freq = 0;
    for (int j = 0; j < i; j++)
    {
        if (a[j] == 1)
        {
            freq++;
            max = max > freq ? max : freq;
        }
        else
        {
            freq = 0;
            max = max > freq ? max : freq;
        }
    }
    printf("%d", max);

    return 0;
}