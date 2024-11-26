#include "stdio.h"

int main(){
    int a[] = { 8, 9, 10, 11, 12, 19, 22, 32, 34, 67};
    int n = sizeof(a) / sizeof(int);
    int low = 0 , high = n - 1;
    int target = 19;
    int res = -1 , count = 0;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(target == a[mid]){
            res = mid;
            break;
        }
        if(target < a[mid]){
            high = mid - 1;
            count++;
        }
        if(target > a[mid]){
            low = mid + 1;
            count++;
        }
    }
    if(res != -1){
        printf("%d - %d" , res , count);
    }else{
        printf("%d " , res);
    }
}
