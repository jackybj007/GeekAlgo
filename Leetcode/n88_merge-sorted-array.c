void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m - 1, j = n -1, k = m + n -1;
    while (j >= 0) {
        nums1[k--] = (i == -1 || nums1[i] < nums2[j]) ? nums2[j--] : nums1[i--];
    }
}
