#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void selection_sort(int *arr, int len);

int main()
{
    int *arr;
    arr = (int *)malloc(sizeof(int) * 20);

    srand(time(NULL));

    int i;
    for (i = 0; i < 20; i++)
    {
        *(arr + i) = rand() % 100;
    }
    selection_sort(arr, 20);
    for (i = 0; i < 20; i++)
    {
        printf("%d ", *(arr + i));
    }

    free(arr);
    getchar();
}

void selection_sort(int *arr, int len)
{
    int i, j, min;
    for (i = 0; i < len - 1; i++)
    {
        min = i;
        for (j = i + 1; j < len; j++)
        {
            if (*(arr + j) < *(arr + min))
                min = j;
        }

        int tmp = *(arr + i);
        *(arr + i) = *(arr + min);
        *(arr + min) = tmp;
    }
}