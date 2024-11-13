int dominantIndex(int* nums, int numsSize) {
    int max = nums[0];
    int idx = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
            idx = i;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (i != idx && max < 2 * nums[i]) {
            return -1;
        }
    }

    return idx;
}
