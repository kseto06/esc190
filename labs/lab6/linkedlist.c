#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LL.h"

void print_list(LL *list) {
    printf("Linked List (size = %d): ", list->size);
    node *temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//Q1
//Append integer new_elem to linked list my_list
void LL_append(LL* my_list, int new_elem) {
    //Handle 1st case scenario where there is no elements 
    if (my_list->head == NULL) {
        my_list->head = (node*)malloc(sizeof(node));
        my_list->head->data = new_elem;
        return;
    }

    //Advance the node until the last element NULL
    node* cur = my_list->head;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = (node*)malloc(sizeof(node));
    cur->next->data = new_elem;
    my_list->size++;
}

int validate_list_length(LL* my_list) {
    node* cur = my_list->head;
    int counted_length = 0;
    while (cur->next != NULL) {
        cur = cur->next;
        counted_length++;
    }

    return (counted_length == my_list->size) ? 1 : 0;
}

void delete(LL* my_list, int index) {
    if (index < 0 || index > my_list->size) {
        printf("Index out of bounds\n");
        return;
    }

    node* cur = my_list->head;
    node* prev = NULL;

    int i;
    for (i = 0; i < index; i++) {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL) {
        // Deleting the head node
        my_list->head = cur->next;
    } else {
        prev->next = cur->next;
    }

    //Case where its the last element
    if (i == index-1) {
        cur->next = NULL;
    }

    free(cur);
    my_list->size--;
}

// int main() {
//     LL my_list = {NULL, 0};
//     LL_append(&my_list, 10);
//     LL_append(&my_list, 20);
//     LL_append(&my_list, 30);

//     print_list(&my_list);

//     printf("%d\n", validate_list_length(&my_list));

//     delete(&my_list, 2);
//     print_list(&my_list);

//     return 0;
// }