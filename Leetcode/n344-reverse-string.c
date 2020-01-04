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
