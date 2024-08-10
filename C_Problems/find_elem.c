#include <stdio.h>
#include <stdbool.h>

bool isValuePresentAsIndex(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int main(){
    int arr[] = {1 , 6 ,  3 , 5 , 8 , 7 , 4};
    int MAX_NUM=arr[0] , MIN_NUM=arr[0];
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int j = 0 ; j < n ; j++){
        if(MAX_NUM < arr[j]){
            MAX_NUM = arr[j];
        }
    }
    for(int j = 0 ; j < n ; j++){
        if(MIN_NUM > arr[j]){
            MIN_NUM = arr[j];
        }
    }
    int ans;
    for(int i = MIN_NUM ; i <= MAX_NUM ; i++){
        if(!isValuePresentAsIndex(arr , n , i)){
            ans = i;
            break;
        }
    }
    printf("elem found %d\n" , ans);

    return 0;
}
