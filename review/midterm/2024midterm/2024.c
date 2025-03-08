#include <stdio.h>

int last_occurence(char *str1, char *str2) {
    int idx = 0;
    while (*str1 != '\0' && *str2 != '\0') {
        str1++;
        str2++;
        if (*str1 != *str2) {
            if (idx == 0) {
                return -1;
            } else {
                return idx + 1;
            }
        }
        idx++;
    }
    return idx + 1;
}

int main() {
    char* str1 = "EngSciEngSciTrackOne";
    char* str2 = "Deotre";
    printf("%d\n", last_occurence(str1, str2));
    return 0;
}