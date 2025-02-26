#include <stdio.h>
#include <stdlib.h>
#include "intset.h"

//Initialize intset head
void intset_create(struct intset **s) {
    *s = (struct intset*)malloc(sizeof(struct intset));
    (*s)->head = NULL;
}

//Helper function: Python `in`
int in(int elem, int* array, int arr_sz) {
    for (int i = 0; i < arr_sz; i++) {
        if (elem == array[i]) {
            return 0;
        }
    }

    return -1;
}

//Add elements to the intset
void intset_add(struct intset *s, int *elems, int num_elems) {
    struct node *cur = s->head;
    int elements_seen[200];

    //Advance through existing elements
    int count = 0;
    while (cur->next != NULL) {
        elements_seen[count] = cur->data;
        count++;
        cur = cur->next;
    }

    for (int i = 0; i < num_elems; i++) {
        if (in(elems[i], elements_seen, sizeof(elements_seen)/sizeof(elements_seen[0])) == 0) {
            continue;
        } else {
            cur->next = (struct node*)malloc(sizeof(struct node));
            cur->data = elems[i];
            cur = cur->next;
            elements_seen[count+i] = elems[i];
        }
    }
}

// Is element in intset
int intset_iselem(struct intset *s, int elem) {
   struct node* cur = s->head;
   while (cur->next != NULL) {
        if (cur->data == elem) {
            return 1;
        }
        cur = cur->next;
   }

   return 0;
}

//Remove element from s:
void intset_remove(struct intset *s, int elem) {
    struct node *cur = s->head;
    struct node *prev = NULL;
    while (cur->next != NULL) {
        if (cur->data == elem) { //Remove
            if (prev == NULL) {
                s->head = cur->next; 
            } else {
                prev->next = cur->next;
            }
            
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}

//Unionize two intsets
void intset_union(struct intset *s1, struct intset *s2, struct intset **s3) {
    *s3 = (struct intset *)malloc(sizeof(struct intset));
    int seen_elems[200];

    //Initial s1:
    struct node *cur = s1->head;
    (*s3)->head = cur;
    int count = 0;
    while (cur->next != NULL) {
        cur = cur->next;
        (*s3)->head->next = cur;
        seen_elems[count] = cur->data;
        count++;
    }

    //Initial s2:
    cur = s2->head;
    while (cur->next != NULL) {
        if (in(cur->data, seen_elems, sizeof(seen_elems)/sizeof(seen_elems[0])) == 0) {
            (*s3)->head->next = cur->next;
            seen_elems[count] = cur->next->data;
            count++;
        } else {
            (*s3)->head->next = cur;
            cur = cur->next;
        }
    }
}

int main(void)
{
    printf("Test code for intset\n");
    struct intset *s1;
    struct intset *s2;
    struct intset *s3;
    intset_create(&s1);
    intset_create(&s2);
    
    // Add the elements 5, 4, 4, 10, 4 to s1
    int to_addA[5] = {5, 4, 4, 10, 4};
    int to_addB[4] = {2, 2, 3, 4};
    int to_addC[2] = {10, 12};
    
    intset_add(s1, to_addA, 5); // Add the 5 elements from to_addA to the set s1.
                                // Ignore repetitions
    
    intset_add(s1, to_addC, 2); // Add the 2 elements from to_add
                                // Ignore repetitions
    
    intset_add(s2, to_addB, 3); // Add 2, 2, and 3 to s2. Ignore repetitions.

    
    intset_union(s1, s2, &s3); // Compute the union of the sets
                                      // s1 and s2, and put the result in s3


    printf("Is 2 in s1? %d\n", intset_iselem(s1, 2)); // 0
    printf("Is 3 in s2? %d\n", intset_iselem(s2, 3)); // 1
    printf("Is 4 in s3? %d\n", intset_iselem(s3, 4)); // 1

    intset_remove(s1, 4);      // Remove the element 4 for the set
    printf("Is 4 in s1? %d\n", intset_iselem(s1, 4)); // 0

}