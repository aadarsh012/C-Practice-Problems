/*
Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer. 
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

A slight modification of the problem can be found here.

Example 1:

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as 
{3, 3, 6, 8}. The difference between 
the largest and the smallest is 8-3 = 5
*/

//Solution

#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

void merge(int *a, int beg, int mid, int end)
{
    int i = beg, j = mid + 1, k, index = beg;
    int temp[1000];
    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
        {
            temp[index] = a[i];
            i = i + 1;
        }
        else
        {
            temp[index] = a[j];
            j = j + 1;
        }
        index++;
    }
    if (i > mid)
    {
        while (j <= end)
        {
            temp[index] = a[j];
            index++;
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[index] = a[i];
            index++;
            i++;
        }
    }
    k = beg;
    while (k < index)
    {
        a[k] = temp[k];
        k++;
    }
}

void sort(int *a, int beg, int end)
{
    int mid;
    if (beg < end)
    {
        mid = (beg + end) / 2;
        sort(a, beg, mid);
        sort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

int getMinDiff(int *a, int n, int k)
{
    sort(a, a[0], a[n - 1]);
    int result = a[n - 1] - a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > k)
        {
            int minimum = min(a[0] + k, a[i] - k);
            int maximum = max(a[n - 1] - k, a[i - 1] + k);
            result = min(result, maximum - minimum);
        }
        else
            continue;
    }
    return result;
}

void main()

{
    int a[1000], n, k;
    printf("Enter size of Array: ");
    scanf("%d", &n);
    printf("Enter the modifying number k: ");
    scanf("%d", &k);
    printf("Enter Elements of the array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int difference = getMinDiff(a, n, k);
    printf("The modified array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("The Difference is : %d ", difference);
}