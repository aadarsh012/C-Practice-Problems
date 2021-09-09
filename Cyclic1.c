/*
Given an array, rotate the array by one position in clock-wise direction.
 
Example 1:

Input:
N = 5
A[] = {1, 2, 3, 4, 5}
Output:
5 1 2 3 4

*/

#include <stdio.h>

void rotate(int *a, int n)
{
    int temp = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        a[i + 1] = a[i];
    }

    a[0] = temp;
}

void main()
{
    int a[100], n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter elements of the array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    rotate(a, n);
    printf("the rotated array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}