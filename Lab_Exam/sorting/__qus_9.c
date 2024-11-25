#include "stdio.h"
#include "string.h"

void insertion_sort_strings(char strings[][20], int n) {
    for (int i = 1; i < n; i++) {
        char num_to_insert[20];
        strcpy(num_to_insert, strings[i]);
        int j = i - 1;

        while (j >= 0 && strcmp(strings[j], num_to_insert) > 0) {
            strcpy(strings[j + 1], strings[j]);
            j--;
        }

        strcpy(strings[j + 1], num_to_insert);
    }
}

int main() {
    char strings[5][20] = {
        "Bxnana",
        "Apple",
        "Cherry",
        "Mango",
        "Blueberry"
    };
    int n = sizeof(strings) / sizeof(strings[0]); 
    printf("Before Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    insertion_sort_strings(strings, n);

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
