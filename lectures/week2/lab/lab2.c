// Question 2
#include <stdio.h>
#include <string.h>

char* strcat1(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0') {
        i++;
    }   
    int j = 0;
    while (str2[j] != '\0') {
        str1[i+j] = str2[j];
        j++;
    }

    return str1;
}

char* strcat2(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0') {
        i++;
    }   

    for (int j = 0; str2[j] != '\0'; j++)  {
        str1[i+j] = *(str2+j);
    }

    return str1;

    // i = 0;
    // while (str1[i] != '\0') {
    //     i++;
    // }   
}

int strcmp(const char *s1, const char *s2) {
    int len_s1 = 0;
    while (s1[len_s1] != '\0') {
        len_s1++;
    }   

    int len_s2 = 0;
    while (s2[len_s2] != '\0') {
        len_s2++;
    }   

    if (len_s1 != len_s2) {
        return 1; 
    }

    for (int i = 0; i < len_s1; i++) {
        if (s1[i] != s2[i]) {
            return 1;
        }
    }

    return 0;
}

int my_strcmp_rec(const char *s1, const char *s2) {
    //Base case 1: we end at both strings with \0
    if (*s1 == '\0' && *s2 == '\0') {
        return 0;
    }
    // Base Case 2: difference between ASCII (pointer) values
    if (*s1 != *s2) {
        return *s1 - *s2;
    }
    // Recursive step
    else {
        return my_strcmp_rec(s1+1, s2+1); //s+1 points to the 1st address in the char array/string
    }
}

// Question 4
int binary_search_deluxe_left(int *L, int target, int len) {
    int left = 0;
    int right = len - 1;
    int mid = (int) ((left + right)/2);

    while (left <= right) {
        mid = (int) ((left + right)/2);
        if (L[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int binary_search_deluxe_right(int *L, int target, int len) {
    int left = 0;
    int right = len - 1;

    while (left <= right) {
        int mid = (int) ((left + right)/2);
        if (L[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}

#include <stdlib.h>
int* binary_search_deluxe(int *L, int target, int len) {
    int* res = malloc(2 * sizeof(int)); // allocate global memory
    res[0] = binary_search_deluxe_left(L, target, len);
    res[1] = binary_search_deluxe_right(L, target, len);
    return res;
}

#include <ctype.h>
int my_atoi(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }

    int convert = *str - '0';
    printf("%d\n", convert);
    return convert;
}

int main() {
    // char arr[100] = "Hello";
    // char *arr2 = "World";
    // printf("%s\n", strcat2(arr, arr2));
    // return 0;

    // char s1[] = "abc";
    // char s2[] = "abc";
    // printf("%d\n", my_strcmp_rec(s1, s2));
    // return 0;

    // int arr[] = {1, 2, 3, 10, 10, 10, 10, 12, 12};
    // int *index = binary_search_deluxe(arr, 10, sizeof(arr) / sizeof(arr[0]));
    // printf("%d\n%d\n", index[0], index[1]);
    // return 0;

    char *str = "5";
    int c = my_atoi(str);
    return 0;
}



