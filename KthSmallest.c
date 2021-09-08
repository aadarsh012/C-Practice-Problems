#include <stdio.h>

int kthSmallest(int *a, int l, int h, int k)
{
    int temp;
    if (k > (l + h + 1))
    {
        return 0;
    }
    else
    {
        for (int i = l; i <= h - 1; i++)
        {
            for (int j = i + 1; j <= h; j++)
            {
                if (a[j] < a[i])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        return a[k - 1];
    }
}

void main()
{
    int a[100], size, k;
    printf("Enter Array size: ");
    scanf("%d", &size);
    printf("Enter elements : \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", a + i);
    }
    printf("\n");
    printf("Enter value of K: ");
    scanf("%d", &k);
    int kthSmall = kthSmallest(a, 0, size - 1, k);
    printf("The Kth Smallest no. is : %d", kthSmall);
}