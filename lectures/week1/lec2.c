#include <stdio.h>

void set43(int *p_a) {
  *p_a = 43; 
}

int main(void) {
    /* ARRAYS */
    // Sequence of objects 
    int arr[] = {5, 10, 2};
    printf("%d\n", arr[1]);

    /* POINTERS */
    int a = 42;
    set43(&a); // Will change the value of a to 43 due to * pointer
    
    //a = 43
    int *p_a = &a; //p_a is the address of a
    char *s = "abc"; //s is the address 
    
    *p_a = 42; // put 42 in address p_a
                // a  becomes 42
                
    int arr2[] = {4, 5, 6};
    printf("%d", *arr2); // Pointer of arr is just the 1st element of the array
    

    return 0;
}
