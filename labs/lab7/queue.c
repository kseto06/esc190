#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue {
    int size;
    int *items;
    int front;
    int rear;
} cq;

void init(cq *q) {
    q->size = 5;
    q->items = (int *)malloc(q->size * sizeof(int));
    q->front = -1;
    q->rear = -1;
}

int is_full(cq *q) {
    if ((q->front == 0 && q->rear == q->size - 1) || (q->front == q->rear + 1)) {
        return 1;
    }
    return 0;
}

int is_empty(cq *q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(cq *q, int value) {
    if (is_full(q)) {
        //Resize the block to carry new data
        int new_size = q->size + 1;
        int *new_items = (int *)malloc(new_size * sizeof(int));

        for (int i = q->front, j = 0; j < q->size; j++) {
            new_items[i] = q->items[i];
            i = (i + 1) % q->size;
        }

        q->front = 0;
        q->rear = q->size - 1;
        q->size = new_size;
        free(q->items);
        q->items = new_items;
    }

    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->items[q->rear] = value;
}

int dequeue(cq *q) {
    int value;
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return value;
}

void displayQueue(cq *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = 0;
    for (i = q->front; i != q->rear; i = (i + 1) % q->size) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = q->front; i != q->rear; i = (i + 1) % q->size) {
        printf("%d ", q->items[i]);
    }
    printf("%d\n", q->items[i]);
}

int main() {
    cq q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    displayQueue(&q);

    dequeue(&q);
    displayQueue(&q);

    enqueue(&q, 60);
    displayQueue(&q);

    return 0;
}