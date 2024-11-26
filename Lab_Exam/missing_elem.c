#include "stdio.h"

int main(){
    int a[] = {1 , 3 , 4 , 5};
    int r = -1;
    int n = sizeof(a) / sizeof(int);
    for(int i = 1 ; i <= n ; i++){
        int flag = 0;
        for(int j = 0 ; j < n ; j++){
            if(a[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            r = i;
            break;
        }
    }
    printf("%d " , r);
    return 0;
}
