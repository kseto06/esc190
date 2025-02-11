#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char buffer[200] = "14608512    Shanghai, China";
    char number[200] = "";
    char str[200] = "";
    for (int j = 0; buffer[j] != '\0'; j++) {
        if (isdigit(buffer[j])) {
            strncat(number, &buffer[j], 1);
        } else {
            strncat(str, &buffer[j], 1);
        }
    }
    // Clean leading spaces if any
    while (str[0] == ' ') { 
        memmove(str, str + 1, strlen(str));
    }

    double num = atof(number);

    printf("%s, %f\n", str, num);
    return 0;
}