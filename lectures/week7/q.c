
#include "ArrayList.h"
#include "q.h"
#include <stdio.h>

void create_queue(queue **p_q) {
    (*p_q) = malloc(sizeof(queue));
    create_list(&((*p_q)->list));
}

void destroy_queue(queue *q) {
    destroy_list(q->list);
}

void enqueue(queue *q, int data) {
    insert_list(q->list, data)
}

//Get element at index 0, remove it and return it
void dequeue(queue *q) {
    int ret = q->list->array[0];
    delete_list_ind(q->list, 0);
    return ret;
}

int main() {
    queue *q;
    create_queue(&q);
    enqueue(q, 5);
    enqueue(q, 1);
    enqueue(q, 2);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    destroy_queue(q);
}
