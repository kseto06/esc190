#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Question 7
typedef struct student2 {
    char *name;
    char *student_number;
    int year;
} student2;

void create_block2(student2 **p_p_s, int num_students) {
    student2 *block = malloc(num_students * sizeof(student2));
        
    for (int i = 0; i < num_students; i++) {
        (block+i)->name = NULL;
        (block+i)->student_number = NULL;
        (block+i)->year = 0;
    }
}

//Question 12
#include "student1.h"

//Question 13
void print_file_lines(char *filename, int N) {
    char line[200];
    FILE *fp = fopen(filename, "r");
    for(int i = 0; i < N; i++){
        fgets(line, sizeof(line), fp); //read in at most sizeof(line) characters
        //(including ’\0’) into line.

        //Line is added by fgets:
        printf("%s\n", line);
    }
    fclose(fp);
}

//Question 14:
void average_int_from_file(char *filename) {
    int total = 0;
    int count = 0;
    char line[200];
    FILE *fp = fopen(filename, "r");
    while(fgets(line, sizeof(line), fp)) { //read in at most sizeof(line) characters
        //(including ’\0’) into line.
        int num = atoi(line);
        total += num;
        count++;
    }
    fclose(fp);

    total /= count;
    printf("%d", total);
}

int main() {
    student2 student[5];
    student2 *p_s = student;
    int num_students = 5;
    create_block2(&p_s, num_students);

    student1 s;
    strcpy(s.name, "Hello");
    strcpy(s.student_number, "1111111111");
    s.year = 0;

    return 0;
}