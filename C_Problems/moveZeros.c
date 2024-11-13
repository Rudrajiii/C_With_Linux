void moveZeroes(int* nums, int numsSize) {
        int j = -1;
        for(int num = 0 ; num < numsSize ; num++){
            if(nums[num] == 0){
                j = num;
                break;
            } 
        }
        if(j == -1) return;
        for(int i = j+1 ; i < numsSize ; i++){
            if(nums[i] != 0){
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                j++;
            }
        }
}