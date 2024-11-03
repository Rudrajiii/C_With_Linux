#include <stdio.h>

int main(){
    int m[3][2] = {{1,2},{3,4},{5,6}};
    int n[2][3] = {{1,2,3},{3,4,5}};
    int z[3][3] = {0};

    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            for(int a = 0 ; a < 2 ; a++){
                z[i][j] += m[i][a] * n[a][j];
            }
        }
    }
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            printf("%d\t" , z[i][j]);
        }
        printf("\n"); 
    }
    
    return 0;
}