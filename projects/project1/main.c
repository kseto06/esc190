#include <stdio.h>
#include <stdlib.h>
#include "autocomplete.h"

int main(void)
{
    struct term *terms;
    int nterms;
    read_in_terms(&terms, &nterms, "cities.txt");

    // Test 1: Try printing first 10 terms
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