/*

4 4 4 4 4 4 4  
4 3 3 3 3 3 4   
4 3 2 2 2 3 4   
4 3 2 1 2 3 4   
4 3 2 2 2 3 4   
4 3 3 3 3 3 4   
4 4 4 4 4 4 4 

->> To solve this, you have to find the minimum length between the element and the four sides. Then print the difference (n - min).

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int len = 2 * n - 1;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            int min = i < j ? i : j;
            min = min < len - 1 - j ? min : len - 1 - j;
            min = min < len - 1 - i ? min : len - 1 - i;
            printf("%d ", n - min);
        }
        printf("\n");
    }
    return 0;
}
