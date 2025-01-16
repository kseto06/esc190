#include <stdio.h>

void change_a(int *p_a, int num) {
    *p_a = num;
}

int main() {
    int a[3] = {5, 6, 7};
    change_a(a, 45);
    
    for (int i = 0; i < 3; i++) {
        printf("%d", a[i]);
        printf(" ");
    }

    return 0;
}
