#include "stdio.h"

void swap(int *x , int *y);
void quicksort(int arr[] , int length);
void quicksort_recursion(int arr[] , int low , int high);
int partition(int arr[] , int low , int high);

int main(){
    int arr[] = {11 , 22 , 8 , 8 , 9 , 10 , 34 , 67 , 32 , 12 , 19};
    int n = sizeof(arr) / sizeof(int);
    quicksort(arr , n);
    for(int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

void swap(int *x , int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void quicksort(int arr[] , int length){
    quicksort_recursion(arr , 0 , length - 1);
}
void quicksort_recursion(int arr[] , int low , int high){
    if(low < high){
        int pivot_index = partition(arr , low , high);
        quicksort_recursion(arr , low , pivot_index - 1);
        quicksort_recursion(arr , pivot_index + 1 , high);
    }
}
int partition(int arr[] , int low , int high){
    int pivot_value = arr[high];
    int i = low;
    for(int j = low ; j < high ; j++){
        if(arr[j] <= pivot_value){
            swap(&arr[i] , &arr[j]);
            i++;
        }
    }
    swap(&arr[i] , &arr[high]);
    return i;
}
