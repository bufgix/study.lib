#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

// Soru aslinda bu fonksyon
int *reverse(int arr[], int step)
{
    if (step == 51)
        return arr;
    int t = arr[step];
    arr[step] = arr[100 - (step + 1)];
    arr[100 - (step + 1)] = t;
    return reverse(arr, step + 1);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 200;
    }
    reverse(arr, 0);

    return 0;
}