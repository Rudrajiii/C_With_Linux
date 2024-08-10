#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // target found
        }
        if (arr[mid] < target) {
            left = mid + 1; // search in the right half
        } else {
            right = mid - 1; // search in the left half
        }
    }

    return -1; // target not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    // Ensure the array is sorted
    // (This is a simple example; in practice, the array should be sorted beforehand)
    
    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
