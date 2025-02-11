
#if !defined(STUDENT_H)
#define STUDENT_H

typedef struct student {
    char name[20];
    int age;
    double gpa;
} student;

#endif


// Second time student.h is #included, nothing will happen
// Name of technique = "include guards"
