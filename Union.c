/*
Q-> Find the union between two arrays.
*/

#include <stdio.h>

unionArray(int *a, int n, int *b, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            printf("%d ", a[i++]);
        }
        else if (b[j] < a[i])
        {
            printf("%d ", b[j++]);
        }
        else
        {
            printf("%d ", b[j++]);
            i++;
        }
    }

    while (i < n)
    {
        printf("%d ", a[i++]);
    }
    while (j < m)
    {
        printf("%d ", b[j++]);
    }
}

void main()
{
    int a[100], b[100], n, m;
    printf("Enter Size of first array: ");
    scanf("%d", &n);
    printf("Enter Size of second array: ");
    scanf("%d", &m);
    printf("Enter Elements of first array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    printf("Enter Elements of second array: \n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", b + i);
    }
    unionArray(a, n, b, m);
}