#include <stdio.h>
#include <stdlib.h>  // For malloc and free

#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))

int minMaxGame(int* nums, int numsSize) {
    while(numsSize != 1) {
        int newSize = numsSize / 2;
        int* r = (int*)malloc(newSize * sizeof(int)); // Dynamically allocate memory
        if (r == NULL) {
            // Handle memory allocation failure
            fprintf(stderr, "Memory allocation failed\n");
            return -1;
        }

        int k = 0, c = 0;
        for(int i = 0; i < numsSize; i += 2) {
            if(c % 2 == 0) {
                r[k++] = MIN(nums[i], nums[i + 1]);
            } else {
                r[k++] = MAX(nums[i], nums[i + 1]);
            }
            c++;
        }

        // Copy the results back to nums
        for(int y = 0; y < newSize; y++) {
            nums[y] = r[y];
        }

        numsSize = newSize;
        free(r);  // Free the dynamically allocated memory
    }
    return nums[0];
}

int main() {
    // Example usage
    int nums[] = {1, 3, 5, 2, 7, 6, 8, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Result: %d\n", minMaxGame(nums, numsSize));
    return 0;
}
