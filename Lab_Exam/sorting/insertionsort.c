#include <stdio.h>

void insertion_sort(int a[] , int n){

    for(int i = 1 ; i < n ; i++){
        int num_to_insert = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > num_to_insert){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = num_to_insert;
    }

}

int main(){
    int a[] = {9 , 1 , 3 , 8 , 6};
    int n = sizeof(a)/sizeof(int);
    insertion_sort(a , n);
    for(int i = 0 ; i < 5 ; i++){
        printf("%d\n" , a[i]);
    }
    return 0;
}