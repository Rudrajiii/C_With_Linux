#include <stdio.h>

int main(){
    int bn = 0 , p = 0;
    int nums[] = {3,2,-3,-4};
    int numsSize = sizeof(nums) / sizeof(int);
    for(int num = 0 ; num < numsSize ; num++){
        if(nums[num] > 0) p += nums[num];
        if(nums[num] < 0) p += nums[num];
        if(p == 0) bn++;
    }
    return bn;
}
