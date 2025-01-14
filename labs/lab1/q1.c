#include <stdio.h>

void swap10(int *p_a) {
    *p_a = 10;
}

int main() {
    int a = 5;
    swap10(&a);
    printf("%d\n", a); //Changes to 10
    return 0;
}

