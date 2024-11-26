#include <stdio.h>
int main(){
    printf("Hyyy\n");
    int a = 34;
    int *p = &a;
    printf("%p\n" , p+1);
    printf("%d\n" , *p);
    int array[] = {1 ,20 ,3};
    printf("%d\n" , *(array+1));
    return 0;
}
