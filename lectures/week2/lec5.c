
#include <stdio.h>

typedef int arr_size;

void print_array(int *arr, arr_size sz) {
    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = {5, 6, 7};
    arr_size sz = 3;
    print_array(arr, sz);
    return 0;
}
