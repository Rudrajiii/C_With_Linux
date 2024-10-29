#include <stdio.h>
int main(){
    int x = 5, *p;
    double y = 7.8 , *p1;
    p = &x;
    p1 = &y;
    printf("%p\n" , (void *)p);
    printf("%p\n" , p);
    printf("%d\n" , *p);
    printf("%ld\n",sizeof(int));
    printf("%p\n" , p+1);
    printf("%p\n" , &x);
    *p = 8;
    printf("%d\n" , *p);

    printf("%f\n" , *p1);
    return 0;
}
