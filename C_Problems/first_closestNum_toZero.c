#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

int min(int n1 , int n2){
    if(n1 > n2){
        return n2;
    }else{
        return n1;
    }
}

bool isValuePresentAsIndex(int arr[], int n ,int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int main(){
    int max_int = INT_MAX;
    int arr[] = {2,-1,1};
    int diff , neg = 0 ; - 1;
    int len = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0 ; i < len ; i++){
        diff = abs(arr[i]);
        max_int = min(max_int , diff);

    }
    if(isValuePresentAsIndex(arr , len , max_int)){
        printf("%d\n" , max_int);
    }else{
        printf("%d\n" , neg*max_int );
    }
    return 0;
}
