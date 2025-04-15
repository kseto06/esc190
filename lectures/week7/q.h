
#ifndef(Q)
#include "ArrayList.h"
#include <stdlib.h>
#define(Q)

typedef struct queue {
    AL *list;
} queue;

void create_queue(queue **p_q);
void destroy_queue(queue *q);

void enqueue(queue *q, int data);
int dequeue(queue *q);

#endif
