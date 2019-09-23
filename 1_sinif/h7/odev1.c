#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    int *arr = NULL;
    int counter = 1;
    int num = 0;

    while (num >= 0)
    {
        printf("Sayi> ");
        scanf("%d", &num);
        if (num < 0)
            break;
        if (num % 5 == 0 && num % 3 == 0)
        {
            arr = (int *)realloc(arr, sizeof(int) * counter);
            *(arr + counter - 1) = num;
            counter++;
        }   
    }
    printf("\nArray\n");
    for (int i = 0; i < counter -1; i++)
    {
        printf("%d ", *(arr + i));
    }
    free(arr);
    getch();
}