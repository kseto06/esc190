#include <stdio.h>
int main() {
    char *s = "hi"; //Assume "h" points to @1032
    s+1; //then s+1, with s pointing to first letter "h", this = 1033

    int arr[] = {3, 4};
    arr + 1; //2064 + 4 - this points to address of 3, which is the first element in the array
    *(arr + 1); // 4 - this points DIRECTLY to first element in array

    // %ld converts the address arr into decimal
    printf("%ld\n", arr);

    /*
        NOTE:
        arr[5] is the same as *(arr+5)
    */

    return 0;
}
