/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
*/

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a, int lb, int ub)
{

    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (a[start] < pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end++;
        }
        if (start < end)
        {
            swap(a + start, a + end);
        }
    }
    swap(a + lb, a + end);
    printf("%d", a[0]);
    return end;
}

void quickSort(int *a, int lb, int ub)
{

    while (lb < ub)
    {
        int loc = partition(a, lb, ub);
        quickSort(a, lb, loc - 1);
        quickSort(a, loc + 1, ub);
    }
}

int findDuplicate(int *a, int n)
{
    quickSort(a, 0, n - 1);

    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            return a[i];
        }
    }

    return -1;
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
    int duplicate = findDuplicate(a, n);
    printf("The Duplicate value is: %d", duplicate);
}