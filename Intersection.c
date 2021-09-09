/*
Q-> Find the intersection between two arrays.
*/

#include <stdio.h>

void intersection(int *a, int n, int *b, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                printf("%d ", a[i]);
            }
        }
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
    intersection(a, n, b, m);
}