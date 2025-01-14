#include <stdio.h>

int main() {
    int n = 25;
    printf("%d\n", n);

    char *s = "abc"; 
    printf("String: %s\n", s);
    printf("Char: %c", s[10]);

    char c = '@';
    char *p_c = &c; //& = "address of"

    return 0;
}
