#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct LL{
    node *head;
    int size;
} LL;

// append integer new_elem to linked list my_list
void LL_append(LL *my_list, int new_val, int i) {
    node *new = (node *)malloc(sizeof(node));
    new->data = new_val;
    new->next = NULL;

    if (i == 0) {
        new->next = my_list->head;
        my_list->head = new;
    } else {
        node *cur = my_list->head;

        for (int pos = 0; pos < i - 1 && cur != NULL; pos++) { 
            cur = cur->next;
        }

        new->next = cur->next;
        cur->next = new;
    }

    my_list->size++;
}

int main() {
    node* node1 = malloc(sizeof(node));
    node* node2 = malloc(sizeof(node));
    node* node3 = malloc(sizeof(node));
    node1->data = 10; node1->next = node2;
    node2->data = 20; node2->next = node3;
    node3->data = 30; node3->next = NULL;

    LL my_list;
    my_list.head = node1;
    my_list.size = 3;

    LL_append(&my_list, 42, 1); // Insert 42 at index 1

    node *cur = my_list.head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");

    // Free memory
    cur = my_list.head;
    while (cur != NULL) {
        node* temp = cur;
        cur = cur->next;
        free(temp);
    }

    return 0;
}
