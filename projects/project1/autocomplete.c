#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
/*
Compiling with ASan: 
clang -fsanitize=address -g -o autocomplete autocomplete.c

Running:
./autocomplete
*/

// Part 1

typedef struct term {
    char term[200];
    long long weight;
} term;
//Helper function for lexicographic sorting
int compare_terms(const void *a, const void *b) {
    return strcmp(((const term *)a)->term, ((const term *)b)->term); //Compare terms of a and b with strcmp
}

void read_in_terms(term** terms, int* pnterms, char* filename) {
    /*
    Create a block of terms in memory, sorted in alphabetical order

    Inputs:
    - term: term** double pointer for an array of terms in term
    - pnterms: int* single pointer to get address of number of terms
    - filename: char* string value of the filename "<file>.txt"
    */

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    //Count number of lines in the file, store in *pnterms
    char buffer[200]; //Buffer to store each line
    fgets(buffer, sizeof(buffer), file);
    *pnterms = atoi(buffer); //First line contains the pnterms
    *terms = (term *)malloc((*pnterms) * sizeof(term)); //Allocate term memory

    for (int i = 0; i < *pnterms; i++) {
        fgets(buffer, sizeof(buffer), file);
        char *number = strtok(buffer, "\t");
        (*terms)[i].weight = atof(number);
        strcpy((*terms)[i].term, strtok(NULL, "\r\n"));
        
    }
    fclose(file);

    // Lexiographic sorting - require nested compare_terms function to qsort
    qsort(*terms, *pnterms, sizeof(term), compare_terms);
}

int binary_search(term* terms, int nterms, char* substr, char* specification) {
    /*
    Helper function:
    Returns the index of the first/last occurence of target(substr), given lowest/highest specification.
    */
    int index = -1;
    int left = 0;
    int right = nterms - 1;

    while (left <= right) {
        int mid = (int)((right+left) / 2); 

        //Target reached:
        if (strcmp(terms[mid].term, substr) >= 0 && strncmp(substr, terms[mid].term, strlen(substr)) == 0) {
            index = mid;
            if (strcmp(specification, "left") == 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        //negative lexicographic score
        else if (strncmp(substr, terms[mid].term, strlen(substr)) < 0) {
            right = mid - 1;
        }
        //positive
        else {
            left = mid + 1;
        }
    }

    return index;
}

// Part 2
int lowest_match(term* terms, int nterms, char* substr) {
    return binary_search(terms, nterms, substr, "left");
}

// Part 3
int highest_match(struct term* terms, int nterms, char* substr) {
    /*
    Return the index in terms of the last term that matches the string substr
    Needs to be in O(log(nterms)) time -- i.e., use binary search (right)  
    */
    return binary_search(terms, nterms, substr, "right");
}


int compare(const void * a, const void * b){
    term *term_a = (struct term *)a;
    term *term_b = (struct term *)b;
    return term_b->weight - term_a->weight;
}

void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr){
    int hm = highest_match(terms, nterms, substr);
    int lm = lowest_match(terms, nterms, substr);

    if (hm < 0 || lm < 0){
        *n_answer = 0;
        return;
    }

    *n_answer = (hm - lm) + 1;
    *answer = (term*)malloc(sizeof(term) * (*n_answer));

    int num = 0;

    for (int i = lm; i < lm + *n_answer; i++){
        strcpy((*answer + num)->term, (terms + i)->term);
        (*answer + num)->weight = (terms + i)->weight;
        num++;
    }
    qsort(*answer, *n_answer, sizeof(term), compare);
}
