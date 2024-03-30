#include <stdio.h>
#include <stdlib.h>

void insertionSort(float bucket[], int size) {
    for (int i = 1; i < size; ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    int MAX_BUCKET_SIZE = 100; 
    float b[n][MAX_BUCKET_SIZE];

    int bucketSizes[n];
    for (int i = 0; i < n; ++i) {
        bucketSizes[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi][bucketSizes[bi]++] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        insertionSort(b[i], bucketSizes[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = b[i][j];
        }
    }
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);

    printf("Sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%.4f ", arr[i]);
    }
    return 0;
}
