#include <stdio.h>
int abs(int n){
    int neg = -1;
    return n > 0 ? n : neg * n;
}
int main(){
    int nums[] = {1,2,2,1};
    int k = 1;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int count = 0;
    for(int i = 0 ; i < numsSize ; i++){
        for(int j = i+1 ; j < numsSize ; j++){
            if(abs(nums[i] - nums[j]) == k) count++;
        }
    }
    printf("count : %d\n" , count);
    return 0;

}