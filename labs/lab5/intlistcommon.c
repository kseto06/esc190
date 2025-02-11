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

void list_destroy(IntList* list) {
    free(list);
    free(list->data);
}

int list_get(IntList* list, int index) {
    return list->data[index];
}

int main() {
    return 0; 
}