#include <stdio.h>
#include <string.h>

typedef struct student1 {
    char name[3];
    int age;
} student1; 

void change_name(student1* s, char* new_name) {
    strcpy(s->name, new_name);
}

