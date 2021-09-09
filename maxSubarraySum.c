/*
Q-> Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.

Example 1:

Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9

Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.

Time Complexity = O(N)
*/

//Solution

#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int maxSubarraySum(int *a, int n)
{
    // int sum = 0;
    // int maxSum = a[0];
    // int negCount = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (a[i] < 0)
    //     {
    //         negCount++;
    //     }
    //     if (sum + a[i] < 0)
    //     {
    //         sum = 0;
    //     }
    //     else
    //     {
    //         sum += a[i];
    //         maxSum = max(sum, maxSum);
    //     }
    // }
    // if (negCount == n)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         maxSum = max(maxSum, a[i]);
    //     }
    // }
    // return maxSum;

    //Kadane's Algorithm
    int dp[100];
    dp[0] = a[0];
    int maxSum = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(a[i], dp[i - 1] + a[i]);
        if (dp[i] > maxSum)
        {
            maxSum = dp[i];
        }
    }
    return maxSum;
}

void main()
{
    int a[100], n;
    printf("Enter size of Array: ");
    scanf("%d", &n);
    printf("Enter Elements of the array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int maxSum = maxSubarraySum(a, n);
    printf("The max sum is : %d", maxSum);
}