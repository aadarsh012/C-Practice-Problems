/*

You are given sides of a triangle in a struct. Use it to find its area using herons Formula.
then sort the array of triangles in ascending order of areas.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle *tr, int n)
{
    /**
	* Sort an array a of the length n
	*/
    int p, q, r;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            p = tr[i].a;
            q = tr[i].b;
            r = tr[i].c;
            double semiI = (p + q + r) / 2.0;
            double semiJ = (tr[j].a + tr[j].b + tr[j].c) / 2.0;
            double areai = sqrt(semiI * (semiI - p) * (semiI - q) * (semiI - r));
            double areaj = sqrt(semiJ * (semiJ - tr[j].a) * (semiJ - tr[j].b) * (semiJ - tr[j].c));
            if (areai > areaj)
            {
                triangle temp = tr[i];
                tr[i] = tr[j];
                tr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}