#include <stdio.h>

struct pair
{
    int min;
    int max;
};

struct pair minMax(int *a, int n)
{
    struct pair minmax;
    if (n == 1)
    {
        minmax.max = *a;
        minmax.min = *a;
        return minmax;
    }
    else
    {
        if (a[0] > a[1])
        {
            minmax.max = a[0];
            minmax.min = a[1];
        }
        else
        {
            minmax.max = a[1];
            minmax.min = a[0];
        }
        for (int i = 2; i < n; i++)
        {
            if (a[i] > minmax.max)
            {
                minmax.max = a[i];
            }
            if (a[i] < minmax.min)
            {
                minmax.min = a[i];
            }
        }
        return minmax;
    }
}

void main()
{
    int size, a[100], minimum;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter the elements :\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", a + i);
    }
    printf("\n");
    struct pair minmax = minMax(a, size);
    printf("the minimum is : %d\n", minmax.min);
    printf("the maximum is : %d", minmax.max);
}