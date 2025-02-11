#include <stdio.h>
#include <stdlib.h>

int linear_search(int *a, int sz, int elem) {
    for (int i = 0; i < sz; i++) {
        if (a[i] == elem) {
            return i;
        }
    }
    return 0;
}

void reverse_arr(int *arr, int sz) {
    int *result = malloc(sz * sizeof(int));
    for (int i = sz; i >= 0; i--) {
        result[sz-i-1] = arr[i];
    }

    // Print array
    // for (int i = 0; i < sz; i++) {
    //     printf("%d ", result[i]);
    // }

    free(result);
}

int main() {
    // int arr[] = {1,2,3,4};
    // int target = 3;
    // printf("%d\n", linear_search(arr, 4, target));

    // reverse_arr(arr, 4);

    int n = 42;
    int *p_n = &n;
    printf("%d\n", *p_n);

    int arr1[3] = {5, 6, 7};
    printf("%d\n", *(arr1+1));
}