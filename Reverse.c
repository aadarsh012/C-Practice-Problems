#include <stdio.h>
#define SIZE 100

void main()
{
    int a[SIZE], size, *q = a;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter Elements \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The reversed array is : ");
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d ", i[a]);
    }
}