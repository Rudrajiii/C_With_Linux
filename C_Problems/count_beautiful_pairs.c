#include <stdio.h>
int _gcd(int x , int y){
    while(y != 0){
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int countBeautifulPairs(int* nums, int numsSize){
    int count = 0;
    for(int i = 0 ; i < numsSize ; i++){
        for(int j = 1 ; j < numsSize ; j++){
            if(i < j){
                int re_factor_j = nums[j] % 10;
                while(nums[i] >= 10){
                    nums[i] /= 10; 
                }
                int re_factor_i = nums[i];
                if(_gcd(re_factor_i , re_factor_j) == 1){
                    count++; 
                }

            }
        }
    }
    return count;
}