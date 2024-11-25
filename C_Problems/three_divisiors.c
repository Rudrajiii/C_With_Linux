#include <stdio.h>
int main(){
    int n = 5 , c = 1;
    for(int i = 2 ; i <= n ; i++){
        if(n % i == 0) c++;
    }
    printf("Value of C : %d" , c );
    return 0;
}
