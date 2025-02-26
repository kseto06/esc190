#ifndef LL_H
#define LL_H

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct LL {
    node* head;
    int size;
} LL;

#endif