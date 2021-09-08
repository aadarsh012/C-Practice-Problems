#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

int sort012(int *a, int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            swap(a + i, a + c);
            c++;
        }
    }
    for (int i = c; i < n; i++)
    {
        if (a[i] == 1)
        {
            swap(a + i, a + c);
            c++;
        }
    }
}

void main()
{
    int a[100], n;
    printf("Enter array Length: ");
    scanf("%d", &n);
    printf("enter the elements : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    sort012(a, n);
    printf("the sorted elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}