#include <stdio.h>

int main(){
    int *p , x;
    x = 1025;
    p = &x;
    char *p1;
    p1 = (char *)p; 
    printf("address - %p | value - %d\n" , p ,*p);
    printf("address - %p | value - %d\n" , p1 , *p1);
    printf("address - %p | value - %d\n" , p1+1 , *(p1+1));

    //? Binary of 1025 - 32B rep;
    /*
    b1      b2        b3        b4
00000000   00000000  00000100  00000001
    */

    return 0;
}

