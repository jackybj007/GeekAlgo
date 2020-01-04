/**
 *****************************************************
 * 双指针法调用结果
 * 执行用时 :56 ms, 在所有 C 提交中击败了91.35%的用户
 * 内存消耗 :13.5 MB, 在所有 C 提交中击败了75.79%的用户
 * 时间复杂度：O(N)。执行了 N/2 次的交换
 * 空间复杂度：O(1)。只使用了常数级空间
 *****************************************************
 * 递归调用结果
 * 执行用时 :72 ms, 在所有 C 提交中击败了25.39%的用户
 * 内存消耗 :13.6 MB, 在所有 C 提交中击败了75.42%的用户
 * 时间复杂度：O(N)。执行了 N/2 次的交换
 * 空间复杂度：O(N)。递归过程中使用的堆栈空间
 *****************************************************
**/

void reverseString(char* s, int sSize) {
    char * left, *right, ch;

    left = s;
    right = s + sSize -1;

    while (left < right) {
        ch = *right ;
        *right = *left;
        *left = ch;
        ++ left;
        -- right;
    }

}

void reverseHelp(char * left, char * right) {
    char ch;

    if (left >= right) {
        return;
    }

    ch = *right ;
    *right = *left;
    *left = ch;
    ++ left;
    -- right;
    reverseHelp(left, right);
}

void reverseString(char* s, int sSize) {
    char * left, *right;

    left = s;
    right = s + sSize -1;
    reverseHelp(left, right);

}
