#ifndef PYINTEGER_H
#define PYINTEGER_H

typedef struct pyinteger {
    int* digits;
    int size;
    int capacity;
} pyinteger;

void plusplus(pyinteger* n1);
void add(pyinteger* n1, pyinteger* n2);

#endif