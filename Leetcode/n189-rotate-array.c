void rotate(int* nums, int numsSize, int k) {
    int * copy_nums;
    int i, j;

    k = k % numsSize;
    j = k - 1;

    if ( (numsSize == 1) || (k == 0) ) {
        return;
    }

    copy_nums = (int *)malloc(k * sizeof(int));
    if (copy_nums == NULL) {
        return;
    }

    for (i = numsSize - 1; i >= 0 ; i--) {
        if (j >= 0) {
            copy_nums[j--] = nums[i];
        }
        if (i >= k) {
            if (i-k >= 0) {
                nums[i] = nums[i-k];
            }
        } else {
            nums[i] = copy_nums[i];
        }
    }

    if (copy_nums) {
        free(copy_nums);
    }
}
