#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "autocomplete.h"

/*
Compiling with ASad: 
clang -fsanitize=address -g -o autocomplete autocomplete.c

Running:
./autocomplete
*/

// Part 1

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

    //Count number of lines in the file
    *pnterms = 0;
    int a = 0;
    char buffer[200]; //Buffer to store each line
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        a++;
    }
    *pnterms = a;
    term* p_terms = (term *)malloc((*pnterms) * sizeof(term)); //Allocate term memory
    fseek(file, 0, SEEK_SET); //Reset to zero pointer for reading file

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Parse through each term
        for (int i = 0; i < *pnterms; i++) {
            //Parse through each string value, get number values and string values
            char number[200] = "";
            char str[200] = "";
            for (int j = 0; buffer[j] != '\0'; j++) {
                if (isdigit(buffer[j])) { //Appending digits to number
                    strncat(number, &buffer[j], 1);
                } else { //Appending strs/chars to str
                    strncat(str, &buffer[j], 1);
                }
            }
            // Clean first element space if any
            while (str[0] == ' ') {
                memmove(str, str+1, strlen(str));
            }

            strcpy(p_terms[i].term, str);
            p_terms[i].weight = atof(number);
        }
    }
    fclose(file);

    // Lexiographic sorting - require nested compare_terms function to qsort
    qsort(p_terms, *pnterms, sizeof(term), compare_terms);
}

int binary_search(term* terms, int nterms, char* substr, char* specification) {
    /*
    Helper function:
    Returns the index of the first/last occurence of target(substr), given lowest/highest specification.
    */
    int left = 0;
    int right = nterms - 1;

    while (left <= right) {
        int mid = (int)((left+right) / 2); 

        //Left, case 1: first occurence; specification = "left" (lowest)
        if (strncmp(terms[mid].term, substr, strlen(substr)) < 0 && strcmp(specification, "left")) {
            left = mid + 1;
        }
        //Left, case 2: 2nd occurence; specification = "right" (highest)
        else if (strncmp(terms[mid].term, substr, strlen(substr)) <= 0 && strcmp(specification, "right")) {
            left = mid + 1;
        }
        //Right
        else {
            right = mid - 1;
        }
    }

    return left;
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

// Part 4
void autocomplete(term** answer, int *n_answer, term* terms, int nterms, char* substr) {
    /*
    The function takes terms (assume it is sorted lexicographically in increasing order), the number of
    terms nterms, and the query string substr, and places the answers in answer, with *n_answer being the
    number of answers. The answers should be sorted by weight in non-decreasing order.
        Sorting with qsort
        See here: https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
        You must use qsort for this question.
    */
}

int main(void)
{
    struct term *terms;
    int nterms;
    read_in_terms(&terms, &nterms, "cities.txt");

    // Test 1: Try printing first 10 terms
    if (terms == NULL) {
        fprintf(stderr, "Error: 'terms' is NULL after read_in_terms. Aborting.\n");
        return 1; // Exit with an error code
    }

    for (int i = 0; i < 10; i++) {
        printf("%s, %f\n", terms[i].term, terms[i].weight);
    }

    printf("%d\n", lowest_match(terms, nterms, "Tor"));
    // highest_match(terms, nterms, "Tor");
    
    // struct term *answer;
    // int n_answer;
    // autocomplete(&answer, &n_answer, terms, nterms, "Tor");
    //free allocated blocks here -- not required for the project, but good practice
    free(terms);
    return 0;
}