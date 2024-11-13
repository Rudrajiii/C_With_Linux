#include <stdio.h>

int unequalTriplets(int* nums, int numsSize) {
    int c=0;
    for(int i=0;i<numsSize;i++) {
        for(int j=i+1;j<numsSize;j++) {
            for(int k=j+1;k<numsSize;k++) {
                if(nums[i]!=nums[j] && nums[j]!=nums[k] && nums[k]!=nums[i]) {
                    c++;
                }
            }
        }
    }
    return c;
}