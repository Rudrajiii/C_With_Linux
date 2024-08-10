#include <stdio.h>
#include <stdlib.h>

void rearrangeArray(int arr[], int n) {
    int* temp = (int*)malloc(n * sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    int j = 0; 
    // Copy positive numbers to temp array first
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            temp[j++] = arr[i];
        }
    }
    // Copy negative numbers to temp array
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            temp[j++] = arr[i];
        }
    }
    // Copy temp array back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    free(temp);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrangeArray(arr, n);
    printf("Rearranged array is: ");
    printArray(arr, n);
    return 0;
}

