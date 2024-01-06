#include <stdio.h>

void swap(int *a, int *b) {
    if (*a != *b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

void selectSort(int arr[], const int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

void insertSort(int arr[], const int size) {
    for (int i = 1; i < size; i++) {
        const int current = arr[i];
        int j;
        for (j = i - 1; (j >=0 && arr[j] > current); --j) {
            arr[j + 1] = arr[j];
        }
        printf("%d\n", j);
        arr[j + 1] = current;
    }
}

int main() {
    int arr[] = {8, 7, 6, 4, 10, 4};
    const int size = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted Array -> ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSorted Array -> ");
    // selectSort(arr, size);
    insertSort(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}