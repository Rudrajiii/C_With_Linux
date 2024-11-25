#include <stdio.h>

void selection_sort(int a[] , int n){
    int i , j , temp , min;
    for(i = 0 ; i < n - 1; i++){
        min = i;
        for(j = i + 1 ; j < n ; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main(){
    int a[] = {9 , 1 , 3 , 8 , 6};
    int n = sizeof(a)/sizeof(int);
    selection_sort(a , n);
    for(int i = 0 ; i < 5 ; i++){
        printf("%d\n" , a[i]);
    }
    return 0;
}