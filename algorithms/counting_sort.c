#include <stdio.h>
#include <stdlib.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n) {

    int max = getMax(arr, n);
    int* countArray = (int*)calloc(max + 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        countArray[arr[i]]++;
    }
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (countArray[i] > 0) {
            arr[index++] = i;
            countArray[i]--;
        }
    }
    free(countArray);
}

int main() {
    
    int inputArray[] = {4, 3, 12, 1, 5, 5, 3, 9};
    int n = sizeof(inputArray) / sizeof(inputArray[0]);

    printf("Array before sorting: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", inputArray[i]);
    }
    printf("\n");
    countSort(inputArray, n);
    printf("Array after sorting: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", inputArray[i]);
    }
    printf("\n");

    return 0;
}
