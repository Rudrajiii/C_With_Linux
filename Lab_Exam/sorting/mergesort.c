#include "stdio.h"

void merge_sort(int a[] , int length);
void recursive_merge_sort(int a[] , int l , int r);
void merge_sorted_arrays(int a[] , int l , int m , int r);

int main(){
    int arr[] = {11 , 22 , 8 , 8 , 9 , 10 , 34 , 67 , 32 , 12 , 19};
    int n = sizeof(arr) / sizeof(int);
    merge_sort(arr , n);
    for(int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

void merge_sort(int a[] , int length){
    recursive_merge_sort(a , 0 , length - 1);
}
void recursive_merge_sort(int a[] , int l , int r){
    if(l < r){
        int m = l + (r - l) / 2;
        recursive_merge_sort(a , l , m);
        recursive_merge_sort(a , m + 1 , r);
        merge_sorted_arrays(a , l , m , r);
    }
}
void merge_sorted_arrays(int a[] , int l , int m , int r){
    int left_array = m - l + 1;
    int right_array = r - m;

    int temp_left[left_array];
    int temp_right[right_array];

    int i , j , k;
    for(int i = 0 ; i < left_array ; i++){
        temp_left[i] = a[l+i];
    }
    for(int i = 0 ; i < right_array ; i++){
        temp_right[i] = a[m+1+i];
    }
    for(i=0 , j = 0 , k = l ; k <= r ; k++){
        if(i < left_array &&
        (j >= right_array || temp_left[i] <= temp_right[j])){
            a[k] = temp_left[i];
            i++;
        }else{
            a[k] = temp_right[j];
            j++;
        }
    }
}

