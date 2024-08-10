#include <stdio.h> 
void findSubarrayWithSum(int arr[], int n, int target_sum) { 
    int start = 0, current_sum = 0; 
    for (int end = 0; end < n; end++) { 
        current_sum += arr[end]; 
        while (current_sum > target_sum && start <= end) { 
            current_sum -= arr[start]; 
            start++; 
        } 
        if (current_sum == target_sum) { 
            printf ("Subarray with the given sum found between indices %d and %d\n", start, end); 
            return; 
        } 
    } 
    printf ("No subarray with the given sum found.\n"); 
} 
int main() { 
    int arr[] = {1, 4, 20, 3, 10, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int target_sum = 13; 
    findSubarrayWithSum(arr, n, target_sum); 
    return 0; 
} 
