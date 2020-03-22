#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n);
void swap(int *xp, int *yp);
void selection_sort(int[], int);
void insertion_sort(int[], int);
void generateRandomNumbers(int[], int);
int partition(int[], int, int, unsigned int);
void quick_sort(int[], int, int, unsigned int);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int sizes[] = {10000, 20000, 30000};

    for (int i = 0; i < 3; i++)
    {
        double time_spend = 0.0;
        int arr[sizes[i]];
        generateRandomNumbers(arr, sizes[i]);
        quick_sort(arr, 0, sizes[i], 0); 

        // printf("Running %d... ", sizes[i]);
        clock_t begin = clock();
        selection_sort(arr, sizes[i]);
        clock_t end = clock();

        time_spend += (double)(end - begin) / CLOCKS_PER_SEC;
        // printf("%f \n", time_spend);
        printf("%.3f ", time_spend);
    }

    getchar();
    return 0;
}

void generateRandomNumbers(int arr[], int count)
{
    for (int i = 0; i < count; i++)
    {
        arr[i] = rand() % 50000;
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void selection_sort(int arr[], int len)
{
    int i, j, min;
    for (i = 0; i < len - 1; i++)
    {
        min = i;
        for (j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        int t = arr[i];
        arr[i] = arr[min];
        arr[min] = t;
    }
}

void insertion_sort(int arr[], int len)
{
    int i, j;
    for (i = 1; i < len; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int t = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = t;
            j--;
        }
    }
}

int partition(int arr[], int left, int right, unsigned int reverse)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2]; // pivot is middle element of array

    while (i <= j)
    {
        if (reverse == 0) // Small to large
        {
            while (arr[i] < pivot)
                i++; // No exchange
            while (arr[j] > pivot)
                j--; // No exchange
        }
        else
        { // Large to small
            while (arr[i] > pivot)
                i++; // No exchange
            while (arr[j] < pivot)
                j--; // No exchange
        }

        if (i <= j)
        {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }
    return i;
}

void quick_sort(int arr[], int left, int right, unsigned int reverse)
{
    int index = partition(arr, left, right, reverse);
    if (left < index - 1)
        quick_sort(arr, left, index - 1, reverse);
    if (index < right)
        quick_sort(arr, index, right, reverse);
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}