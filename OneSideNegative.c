/* An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.

 Examples : 

 Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
 Output: -12 -13 -5 -7 -3 -6 11 6 5

 Time Complexity : O(N)
 */

//Solution

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void oneSideNegative(int *a, int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
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
    oneSideNegative(a, n);
    printf("the array with negatives on one side is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}