
# include <stdio.h>

int main() {
    int a = 42;

    printf("%d  ", a);

    printf("%ld ", &a);

    printf("%ld ", *a);
    return 0;
}
