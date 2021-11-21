/*
To sort a given array of strings into lexicographically increasing order or into an order in which the string with the lowest length appears first, a sorting function with a flag indicating the type of comparison strategy can be written. The disadvantage with doing so is having to rewrite the function for every new comparison strategy.

A better implementation would be to write a sorting function that accepts a pointer to the function that compares each pair of strings. Doing this will mean only passing a pointer to the sorting function with every new comparison strategy.

 Write functions to sort the given array lexicographically, reverse lexi, length wise(if same length, then print them lexicographically) and acc to no. of distinct chars.

 Sample input :
    4
    wkue
    qoi
    sbv
    fekls

 Sample output :
    fekls
    qoi
    sbv
    wkue

    wkue
    sbv
    qoi
    fekls

    qoi
    sbv
    wkue
    fekls

    qoi
    sbv
    wkue
    fekls
*/

//code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char *a, const char *b)
{
    int result;
    int compare = strcmp(a, b);
    result = compare > 0 ? 0 : 1;

    return result;
}

int lexicographic_sort_reverse(const char *a, const char *b)
{
    int result;
    int compare = strcmp(b, a);
    result = compare > 0 ? 0 : 1;

    return result;
}

#define CHARS 26
int distinct_chars(const char *a)
{
    int dist = 0;
    int chars[CHARS] = {0};

    while (*a != '\0')
    {
        int chr = (*a++) - 'a';
        if (chr < CHARS)
            chars[chr]++;
    }

    for (int i = 0; i < CHARS; i++)
        if (chars[i])
            dist++;

    return dist;
}

int sort_by_number_of_distinct_characters(const char *a, const char *b)
{
    if (distinct_chars(a) < distinct_chars(b))
    {
        return 1;
    }
    else if (distinct_chars(a) > distinct_chars(b))
    {
        return 0;
    }
    else
    {
        return lexicographic_sort(a, b);
    }
}

int sort_by_length(const char *a, const char *b)
{
    if (strlen(a) < strlen(b))
    {
        return 1;
    }
    else if (strlen(a) > strlen(b))
    {
        return 0;
    }
    else
    {
        return lexicographic_sort(a, b);
    }
}

void string_sort(char **arr, const int len, int (*cmp_func)(const char *a, const char *b))
{
    int result;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            result = cmp_func(*(arr + i), *(arr + j));
            if (result == 0)
            {
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    char **arr;
    arr = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}