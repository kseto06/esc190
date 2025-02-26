#include <stdio.h>
#include <stdlib.h>

/*
ASan: clang -fsanitize=address -g -o midterm2023 midterm2023.c
*/

//Q1: 
double my_atof(char *str) {
    double result = 0.0;
    char* counter = str;
    int size_int = 0;
    int size_decimals = 0;

    //Get the size of the ints up to the decimal place
    while (*counter != '.' && *counter != '\0') {
        size_int++;
        counter++;
    }

    for (int i = 0; i < size_int; i++) {
        int power = 1;
        for (int j = 0; j < size_int - i - 1; j++) { // -1 accounts for the fact that the ones digit doesn't need to be multiplied
            power *= 10;
        }

        result += ((*str) - '0') * power;
        //printf("%f\n", result);
        str++;
    }

    //Get the size of the decimals up to the end of string
    if (*str == '.' && *counter == '.') { 
        counter++;
        str++; //Skip decimal point
    }

    while (*counter != '\0') {
        size_decimals++;
        counter++;
    }

    for (int i = 0; i < size_decimals; i++) {
        double power = 1;
        for (int j = 0; j < i + 1; j++) {
            power /= 10;
        }

        result += ((*str) - '0') * power;
        //printf("%f\n", ((*str) - '0') * power);
        str++;
    }

    return result;
}

// Q2:
int my_strncmp(char* str1, char* str2, int num) {
    //Base case: str1 = NULL or str2 = NULL
    //Base case: num = 0, meaning don't check anymore characters
    if (num == 0 || *str1 == '\0' || *str2 == '\0') {
        if (*str1 > *str2) {
            return 1;
        } else if (*str1 == *str2) {
            return 0;
        } else {
            return -1;
        }
    }

    //Base case: Early stopping when str1 and str2 pointers differ
    if (*str1 != *str2) {
        return (*str1 > *str2) - (*str1 < *str2);
    }

    //Recursive Step:
    //Increment pointers and subtract num
    else {
        str1++;
        str2++;
        return my_strncmp(str1, str2, num - 1);
    }
}

// Q4:


int main() {
    printf("%f\n", my_atof("523.12"));
    printf("%d\n", my_strncmp("ESC180", "ESC190", 4));
    return 0;
}