#include "LL.h"
#include "linkedlist.c"

int main() {
    LL my_list = {NULL, 0};
    LL_append(&my_list, 10);
    LL_append(&my_list, 20);
    LL_append(&my_list, 30);

    print_list(&my_list);

    printf("%d\n", validate_list_length(&my_list));

    delete(&my_list, 2);
    print_list(&my_list);

    return 0;
}