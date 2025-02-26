#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
/*
ASan: clang -fsanitize=address -g -o midterm2023 midterm2023.c
*/

//Q1
typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct LL {
    node* head;
    int size;
} LL;

//Append integer new_elem to linked list my_list
void LL_append(LL* my_list, int new_elem) {
    //Handle 1st case scenario where there is no elements 
    if (my_list->head == NULL) {
        my_list->head = (node*)malloc(sizeof(node));
        my_list->head->data = new_elem;
        return;
    }

    //Advance the node until the last element NULL
    node* cur = my_list->head;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = (node*)malloc(sizeof(node));
    cur->next->data = new_elem;
    my_list->size++;
}

//Q2:
char* strcat_rec(char* dest, char* src) {
    //Base case: when src fully appended, return full string
    if (*src == '\0') {
        return dest;
    }

    //Otherwise advance dest 
    if (*dest != '\0') {
        return strcat_rec(dest + 1, src);
    }

    //Once dest fully advanced, copy src
    *dest = *src;
    *(dest+1) = '\0';
    return strcat_rec(dest + 1, src + 1);
}

//Q3:
typedef struct business {
    int phone_number[10];
    char* name;
} business;

void read_numbers(const char* filename, business** whitepages, int* size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL || !file) {
        perror("Failed to open file");
        exit(1);
    }

    char buffer[256];
    
    //Read first line to get the number of businesses
    fgets(buffer, sizeof(buffer), file);
    *size = atoi(buffer);

    //Initialize array to store the businesses
    business* businesses = (business*)malloc(sizeof(business) * (*size));

    //Read the numbers for each business iteratively
    for (int i = 0; i < *size; i++) {
        fgets(buffer, sizeof(buffer), file);
        //Split up the phone numbers and the company names
        char* number = strtok(buffer, " \t"); //Read to tab
        char* name = strtok(NULL, "\r\n"); //Read to endl

        printf("%s: %s\n", name, number);

        //Store numbers into business
        for (int j = 0; j < 10; j++) {
            businesses[i].phone_number[j] = number[j] - '0';
        }

        //Store name into business;
        strcpy(businesses[i].name, name);
    }

    *whitepages = businesses;
    fclose(file);
}

void free_numbers(business* whitepages, int size) {
    free(whitepages);
}

//Q4:
typedef struct daylight {
    int hours;
    int minutes;
} daylight;

void create_daylight_pt_block(daylight** block, int *data, int n){
    *block = (daylight*)malloc(sizeof(daylight) * n/2);
    for (int i = 0; i < n; i++) {
        (*block)[i].hours = data[2*i];
        (*block)[i].minutes = data[2*i+1];
    }
}

void create_Toronto() {
    daylight* block = NULL;
    int n = 2;
    int data[] = {11, 29, 12, 9}; 
    create_daylight_pt_block(&block, data, n);
}

void print_hours_in_block() {
    daylight* block = NULL;
    int n = 2;
    int data[] = {11, 29, 12, 9}; 
    create_daylight_pt_block(&block, data, n);
    printf("%d\n", block[1].hours);
}

int main() {
    // char str1[50] = "hello";
    // char str2[] = "world";
    // strcat_rec(str1, str2);
    // printf("%s\n", str1);

    // business* businesses = NULL;
    // int size = 0;
    // read_numbers("businesses.txt", &businesses, &size);
    // for (int i = 0; i < 3; i++) {
    //     printf("%s: %d\n", businesses[i].name, businesses[i].phone_number[i]);
    // }

    print_hours_in_block();

    // pyinteger n1 = {10099, 5, 10};
    // plusplus(&n1);

    // for (int i = 0; i < n1.size; i++) {
    //     printf("%d", n1.digits[i]);
    // }

    return 0;
}