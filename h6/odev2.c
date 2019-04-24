#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int find_bit(int num, int index);

int main()
{
    int *arr, *arr_result;
    arr = (int *) malloc(sizeof(int) * 100);
    arr_result = (int *) malloc(sizeof(int));

    srand(time(NULL));
    int i;
    for (i = 0; i < 100; i++)
    {
        *(arr + i) = rand()%100;
    }

    int counter = 0;
    for (i = 0; i < 100; i++)
    {
        if (find_bit(*(arr + i), 5) == 0)
        {
            arr_result = (int *) realloc(arr_result, sizeof(int) * (counter + 1));
            *(arr_result + counter) = *(arr + i);
            counter++;
        }
    }
    for (i = 0; i < counter; i++){
        printf("%d ", *(arr_result + i));
    }
    getchar();

}

int find_bit(int num, int index)
{
    if (num & 1 << (index - 1)) return 1;
    return 0;
}