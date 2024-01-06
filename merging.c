#include <stdio.h>
#include <stdlib.h>

int *merging(int arr1[], int arr2[], const int size1, const int size2) {
    int i = 0, j = 0, k = 0;
    int *final = (int *) malloc(sizeof(int) * (size1 + size2));
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            final[k++] = arr1[i++];
        } else {
            final[k++] = arr2[j++];
        }
    }
    while (i < size1) {
        final[k++] = arr1[i++];
    }
    while (j < size2) {
        final[k++] = arr2[j++];
    }
    return final;
}

int main() {
    int a[] = {1, 2, 4, 8, 12};
    int b[] = {4, 6, 9, 10};
    int *c = merging(a, b, 5, 4);
    for (int i = 0; i < 9; i++) {
        printf("%d ", c[i]);
    }
    free(c);
    return 0;
}
