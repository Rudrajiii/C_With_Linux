#include <stdio.h>
#include <stdlib.h>

void createArray(int **arr, int *n) {
    printf("Enter the size of the array: ");
    scanf("%d", n);
    *arr = (int*)malloc(*n * sizeof(int));
    if (*arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter %d elements: ", *n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &((*arr)[i]));
    }
}

void insertElement(int **arr, int *n, int element, int position) {
    if (position < 0 || position > *n) {
        printf("Invalid position!\n");
        return;
    }
    *arr = (int*)realloc(*arr, (*n + 1) * sizeof(int));
    if (*arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = *n; i > position; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[position] = element;
    (*n)++;
}

void deleteElement(int **arr, int *n, int position) {
    if (position < 0 || position >= *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = position; i < *n - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    *arr = (int*)realloc(*arr, (*n - 1) * sizeof(int));
    if (*arr == NULL && *n > 1) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    (*n)--;
}

int searchElement(int *arr, int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

void findMaxMin(int *arr, int n, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

void displayArray(int *arr, int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr = NULL;
    int n = 0;
    int choice, element, position, max, min;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create array\n");
        printf("2. Insert element\n");
        printf("3. Delete element\n");
        printf("4. Search element\n");
        printf("5. Find max and min\n");
        printf("6. Display array\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createArray(&arr, &n);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position: ");
                scanf("%d", &position);
                insertElement(&arr, &n, element, position);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteElement(&arr, &n, position);
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &element);
                position = searchElement(arr, n, element);
                if (position != -1) {
                    printf("Element found at index: %d\n", position);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 5:
                findMaxMin(arr, n, &max, &min);
                printf("Maximum element: %d\n", max);
                printf("Minimum element: %d\n", min);
                break;
            case 6:
                displayArray(arr, n);
                break;
            case 7:
                free(arr);
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}

