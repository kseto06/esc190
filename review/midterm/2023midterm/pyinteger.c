#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pyinteger.h"

void plusplus(pyinteger* n1) {
    bool carry_over = false;
    for (int i = n1->size - 1; i >= 0; i--) {
        if (n1->digits[i] == 9) {
            //Handle last case
            if (i == 0) {
                n1->digits[i] = 10;
            } else {
                n1->digits[i] = 0;
            }  
            carry_over = true;
        } else if (carry_over == true) {
            n1->digits[i]++;
            carry_over = false;
        }
    }
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void add(pyinteger* n1, pyinteger* n2) {
    int carry_over = 0;

    for (int i = min(n1->size, n2->size) - 1; i >= 0; i--) {
        int value = n1->digits[i] + n2->digits[i] + carry_over; //Total value
        carry_over = 0; //Reset back carry_over after adding it to the value
        int digit = value; //Stores the digit of the value 

        //Handle last number case:
        if (i == 0) {
            n1->digits[i] = value;
            return;
        }

        while (digit >= 10) {
            digit -= 10;
            carry_over++;
        }

        n1->digits[i] = digit;
    }   
}

int main() {
    int digits[] = {1, 0, 9, 9, 9};
    pyinteger n1 = {digits, 5, 10};
    plusplus(&n1);

    for (int i = 0; i < n1.size; i++) {
        printf("%d", n1.digits[i]);
    }

    int digits2[] = {6, 7};
    pyinteger n2 = {digits2, 2, 10};
    int digits3[] = {8, 9};
    pyinteger n3 = {digits3, 2, 10};
    add(&n2, &n3);
    printf("\n");
    for (int i = 0; i < n2.size; i++) {
        printf("%d", n2.digits[i]);
    }

    return 0;
}