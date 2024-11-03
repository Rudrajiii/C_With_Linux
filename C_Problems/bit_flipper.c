#include <stdio.h>
//? Perfect Algorithm Of Bit Flipping
int main() {
    int n, i = 0, x,s = 0,z=0;
    printf("Enter a number:");
    scanf("%d",&n);
    while(n!=0)
    {
        x=n%2;
        n=n/2;
        if(x==0)
        {
            x=1;
            s=s+pow(10,i)*x;
            z=z+pow(10,i)*x;
        }
        else if(x==1)
        {
            s=s+pow(10,i)*x;
        }
        i++;
    }
    printf("%d",s-z);
    return 0;
}