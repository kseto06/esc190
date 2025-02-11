
#include <stdio.h>

void change_arr(int *arr) {
    arr[0] = 3;
    arr[1] = 4;
}

void dont_change_arr(int *arr) {
    arr = 0;
}

int main() {
    int arr[] = {5, 6, 7};
    change_arr(arr);
    printf("%d\n%d\n", arr[0], arr[1]);
    dont_change_arr(arr);
    return 0;
}
