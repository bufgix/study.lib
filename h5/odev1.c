#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

/*
    @author: Ömer (Bufgix) Oruç
**/

void selection_sort(int[], int);
void insertion_sort(int [], int);

int main()
{
    int i, j, nums[100];
    srand(time(NULL));
    // Create main nums array
    for(i = 0; i < 100; i++)
    {
        nums[i] = rand()%100;
    }

    // Separate nums
    int nums1[50], nums2[50];
    for (i = 0; i < 50; i++)
    {
        nums1[i] = nums[i];
        nums2[i] = nums[50 + i];
    }
    selection_sort(nums1, 50); // Sorting first half with selection sort
    insertion_sort(nums2, 50); // Sorting second half with insertion sort
    
    for (i = 0; i < 50; i++) printf("%d-", nums1[i]);
    for (i = 0; i < 50; i++) printf("%d-", nums2[i]);
    
    getch();
}

void selection_sort(int arr[], int len)
{ 
    int i, j, min;
    for (i = 0; i < len - 1; i++)
    { 
        min = i;
        for (j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min]) min = j;
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
        while(j > 0 && arr[j - 1] > arr[j]){
            int t = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = t;
            j--;
        }
    }
}