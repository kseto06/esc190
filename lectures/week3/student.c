
#include <stdio.h>
#include "student.h"

void hack_gpa(student *s) { //Can include student because student.h included
    s->gpa = 4.0;
}

int main() {
    student s;
    s.age = 20;
    s.gpa = 3.9;
    hack_gpa(&s);
    printf("%f", s.gpa);
    return 0;
}
