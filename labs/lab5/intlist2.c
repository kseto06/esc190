#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intlist.h"

void create_list_from_data(IntList **p_IntList, int *data_arr, int size) {
    IntList* new_IntList = (IntList*)malloc(sizeof(IntList));

    // Append data
    new_IntList->data = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        new_IntList->data[i] = data_arr[i];
    }

    //Initialize size and capacity
    new_IntList->size = size;
    new_IntList->capacity = size;

    *p_IntList = new_IntList;

}

void list_append(IntList *list, int new_elem) {
    int *updated_data = (int *)realloc(list->data, sizeof(list->data) * (list->capacity+1));
    *(updated_data + list->size) = new_elem; //Advance array to the correct element using pointers
    list->size++;
    list->capacity++;
} 

void list_insert(IntList *list, int new_elem, int index) {
    // int *updated_data = (int *)realloc(list->data, sizeof(list->data) * (list->size+1));
    
    if (index < list->capacity) {
        memmove(list->data + index + 1, // go to position after index
                    list->data + index,     // start at index
                    (list->size - index) * sizeof(int)); //moving size-index number of bytes
    }  

    list->data[index] = new_elem; //Advance array to the correct element using pointers
    list->size++;
    list->capacity++;
}

void list_delete(IntList *list, int index) {
    int* updated_data = (int *)realloc(list->data, sizeof(list->data)*(list->capacity-1));
    for (int i = 0; i < list->size; i++) {
        if (i == index) {
            continue;
        } else if (i > index) {
            updated_data[i-1] = list->data[i];
        } else {
            updated_data[i] = list->data[i];
        }
    }
    list->size--;

    if (list->capacity - list->size >= 2) {
        list->capacity--;
        list->capacity--; //Factor of 2
    }
}

void list_destroy(IntList* list) {
    free(list);
    free(list->data);
}

int list_get(IntList* list, int index) {
    return list->data[index];
}


int main() {
    IntList* p_IntList = NULL;
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data)/sizeof(data[0]);
    create_list_from_data(&p_IntList, data, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", p_IntList->data[i]);
    }
    printf("\n");

    list_append(p_IntList, 6);
    for (int i = 0; i < p_IntList->size; i++) {
        printf("%d ", p_IntList->data[i]);
    }
    printf("\n");

    list_insert(p_IntList, 7, 2);
    for (int i = 0; i < p_IntList->size; i++) {
        printf("%d ", p_IntList->data[i]);
    }
    printf("\n");

    list_delete(p_IntList, 2);
    for (int i = 0; i < p_IntList->size; i++) {
        printf("%d ", p_IntList->data[i]);
    }
    printf("New capacity is: %d\n", p_IntList->capacity);

    list_delete(p_IntList, 2);
    for (int i = 0; i < p_IntList->size; i++) {
        printf("%d ", p_IntList->data[i]);
    }
    printf("New capacity is: %d\n", p_IntList->capacity);

    printf("%d\n", list_get(p_IntList, 2));

    return 0;
}