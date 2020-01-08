void moveZeroes(int* nums, int numsSize){
    int i, j;
    for (i = 0, j = 0; i < numsSize; i ++) {
        if (nums[i] != 0) {
            if (i != j) {
                nums[j] = nums[i];
                nums[i] = 0;
            }
            j ++;
        }
    }
}
