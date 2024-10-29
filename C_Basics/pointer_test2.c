#include <stdio.h>
int main(){
    int x = 5;
    int *p;
    p = &x;
    int **q;
    q = &p;
    int ***r;
    r = &q;
    printf("value of x - %d\n" , x);
    printf("address of p - %p | value of p - %d\n" , p , *p);
    printf("own address of q - %p | address of q - %p | value of q - %d\n" , q , *q , **q);
    printf("own address of r - %p | holded address of r - %p | address of r - %p | value of r - %d\n" , r , *r , **r , ***r);
    ***r = 10;
    **q = *p + 1;
    printf("value of x - %d\n" , x);
    return 0;

}



