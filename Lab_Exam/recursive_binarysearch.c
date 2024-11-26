#include "stdio.h"
#include "time.h"

int recursive_binarysearch(int a[] , int low , int high , int target){
    if(low == high){
        if(a[low] == target){
            return low;
        }else{
            return -1;
        }
    }else{
            int mid = low + (high - low) / 2;
            if(target == a[mid]){
                return mid;
            }
            if(target < a[mid]){
                return recursive_binarysearch(a , low , mid - 1 , target);
            }
            if(target > a[mid]){
                return recursive_binarysearch(a , mid + 1 , high , target);
            }
    }
}

int main(){
    int a[] = { 8, 9, 10, 11, 12, 19, 22, 32, 34, 67};
    int n = sizeof(a) / sizeof(int);
    clock_t start = clock();
    int res = recursive_binarysearch(a , 0 , n - 1 , 19);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%d - %f" , res , time_taken);
    return 0;
}
