#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int arr[], int len) {
    int max_value = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    return max_value;
}

char* bin(int num) {
    int bits = sizeof(int) * 8;  // Assumes 32-bit integers
    char* bin_str = (char*)malloc(bits + 1);
    bin_str[bits] = '\0';

    for (int i = bits - 1; i >= 0; i--) {
        bin_str[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }

    // Remove leading zeros
    int first_one = 0;
    while (bin_str[first_one] == '0' && first_one < bits - 1) {
        first_one++;
    }

    return strdup(bin_str + first_one);
}

int main() {
    int nums[] = {2, 12, 1, 11, 4, 5};  // Example array
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;  // Example threshold

    int max_elem = max(nums, numsSize);
    char* max_bit = bin(max_elem);

    char** store_bits = (char**)malloc(numsSize * sizeof(char*));
    for (int i = 0; i < numsSize; i++) {
        char* bin_str = bin(nums[i]);
        int diff = strlen(max_bit) - strlen(bin_str);

        if (diff > 0) {
            char* format_bit = (char*)malloc(strlen(max_bit) + 1);
            memset(format_bit, '0', diff);
            strcpy(format_bit + diff, bin_str);
            store_bits[i] = format_bit;
        } else {
            store_bits[i] = bin_str;
        }
    }

    int f_len = numsSize * strlen(max_bit);
    char* f = (char*)malloc(f_len + 1);
    f[0] = '\0';

    for (int i = 0; i < numsSize; i++) {
        strcat(f, store_bits[i]);
    }

    int bit_counters[strlen(max_bit)];
    memset(bit_counters, 0, sizeof(bit_counters));

    for (int i = 0; i < f_len; i++) {
        int bit_position = i % strlen(max_bit);
        bit_counters[bit_position] += (f[i] - '0');
    }

    char* final_res = (char*)malloc(strlen(max_bit) + 1);
    for (int i = 0; i < strlen(max_bit); i++) {
        final_res[i] = (bit_counters[i] >= k) ? '1' : '0';
    }
    final_res[strlen(max_bit)] = '\0';

    int result = strtol(final_res, NULL, 2);
    printf("Result: %d\n", result);

    // Free memory
    free(max_bit);
    for (int i = 0; i < numsSize; i++) {
        free(store_bits[i]);
    }
    free(store_bits);
    free(f);
    free(final_res);

    return 0;
}