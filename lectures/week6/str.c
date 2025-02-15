#include "str.h"
#include <stdio.h>
#include <stdlib.h>

void create_string(mystr** p_p_s) { //Send in &p_s
    *p_p_s = (mystr*)malloc(sizeof(mystr));
    (*p_p_s)->capacity = 100;
    (*p_p_s)->block = (char*)malloc((*p_p_s)->capacity * sizeof(char));
    (*p_p_s)->block[0] = '\0';
    (*p_p_s)->sz = 0;
}

void set_char(mystr *p_s, int ind, char c) {
    if (ind >= p_s->sz || ind < 0) {
        printf("Error: index %d out of bounds\n", ind);
        exit(1);
    }

    (p_s->block)[ind] = c;
}

void append_str(mystr *p_s, const char* src) {
    if (p_s->capacity < p_s->sz + strlen(src)) { //Need to allocate capacity
        int new_capacity = (p_s->capacity + strlen(src) + 1) * 2;
        p_s->block = (char*)realloc(new_capacity * sizeof(char))

        if (p_s->block == NULL) {
            printf("ERROR: string too large when appending\n")
            exit(1);
        }

        p_s->capacity = new_capacity;
        p_s->sz = strlen(src) + p_s->sz;
    }
    p_s->sz = strlen(src) + p_s->sz;
    strcat(p_s->block, src);
}

void destroy_string(mystr* p_s) {
    //Order important since you can't free p_s->block if you free p_s first
    free(p_s->block); 
    free(p_s);
}

char get_char(mystr *p_s, int ind) {
    if (ind < 0 || ind >= p_s->sz) {
        printf("Trying to access an index out of range\n");
        exit(1);
    }
}

char* get_str(mystr *p_s) {
    return p_s->block;
}