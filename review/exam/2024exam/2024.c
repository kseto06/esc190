
#include <stdio.h>
#include <stdlib.h>

int is_increasing(int *arr, int sz) {
    // Base case: sz advanced to zero, that means increasing
    if (sz == 0) {
        return 1;
    } else {
        // increasing
        if (arr[sz-1] > arr[sz-2]) {
            sz--;
            arr = (int *)realloc(arr, sz * sizeof(int));
            return is_increasing(arr, sz);
        } else {
            return 0;
        }
    }

    return 0;
}

int main() {
    int *arr = (int *)malloc(sizeof(arr) * 2);
    arr[0] = 5;
    arr[1] = 4;
    printf("%d\n", is_increasing(arr, 2));
    return 0;
}
