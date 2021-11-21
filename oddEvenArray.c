/*

s = abcdef

print : 
 ace bdf

*/

//code
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d", &T);
    while (T--)
    {
        char *s = (char *)malloc(10000 * sizeof(char));
        scanf("%s", s);
        s = realloc(s, strlen(s) + 1);
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (i % 2 == 0)
            {
                printf("%c", s[i]);
            }
        }
        printf(" ");
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (i % 2 != 0)
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
