#include <stdio.h>

void reverse(int arr[] ,int low ,int high){
    while(low < high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}

int main(){

    int arr[] = {1 , 2 , 3 , 4};
    int len = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    k = k % len;
    int low = 0 , high = len - 1;
    reverse(arr , low , high);
    reverse(arr , 0 , k - 1);
    reverse(arr , k , high);

    for(int i=0 ; i < len ; i++){
        printf("%d " , arr[i]);
    }

    return 0;

}

