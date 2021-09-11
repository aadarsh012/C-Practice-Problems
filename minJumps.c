/*
Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
Note: Return -1 if you can't reach the end of the array.


Example 1:

Input:
N = 11 
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
Output: 3 
Explanation: 
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to last. 
*/

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

int minJumps(int *a, int n)
{
    int jump = 1;
    int step = a[0];
    int result = 0;
    for (int i = 1; i < n; i++)
    {
        if (step >= n - 1)
        {
            break;
        }
        if (step < i)
        {
            return -1;
        }
        result = max(result, i + a[i]);
        if (step == i)
        {
            step = result;
            result = 0;
            jump++;
        }
    }
    return jump;
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
    int jumps = minJumps(a, n);
    printf("The minimum jumps are: %d", jumps);
}
// 2 3 1 1 2 4 2 0 1 1