#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void selection_sort(int *arr, int len);

int main()
{
    int *arr = NULL;
    int num = 0, counter = 1;

    while (num >= 0)
    {
        printf("Sayi> ");
        scanf("%d", &num);
        if (num < 0)
            break;
        arr = (int *)realloc(arr, sizeof(int) * counter);
        *(arr + counter - 1) = num;
        counter++;
    }
    selection_sort(arr, counter - 1);
    printf("\n");
    for (int i = 0; i < counter - 1; i++)
    {
        printf("%d ", *(arr + i));
    }

    getch();
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

        int t = *(arr + i);
        *(arr + i) = *(arr + min);
        *(arr + min) = t;
    }
}