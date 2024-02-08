#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    if (a != b) // Check if addresses are different
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

int partition(int arr[], int left, int right)
{
    int i = left, j = right;
    int pivot = arr[left];

    while (i <= j)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j], &arr[left]);
    return j;
}

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex);
        quickSort(arr, pivotIndex + 1, right);
    }
}

void print_Array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[10] = {10, 5, 8, 9, 3, 6, 15, 12, 16};
    int size = 9;
    int left = 0;
    int right = 8;
    quickSort(arr, left, right);
    print_Array(arr, size);
    // int part = partition(arr, left, right);
    // printf("%d\n", part);
    // print_Array(arr, size);
    return EXIT_SUCCESS;
}
