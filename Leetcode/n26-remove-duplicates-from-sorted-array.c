int removeDuplicates(int* nums, int numsSize){
    int pos = 0;

    if (numsSize < 2) {
        return numsSize;
    }

    for (int i = 1; i < numsSize; i++ ) {
        if (nums[i] != nums[pos]) {
            pos ++;
            if (i != pos) {
                nums[pos] = nums[i];
            }    
        }
    }

    return pos+1;
}
