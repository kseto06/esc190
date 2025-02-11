#include <stdio.h>
#include <stdlib.h>

double my_atof(const char *str)
{
    double res = 0.0;
    int i = 0;
    int sign = 1;

    //Handle sign
    if(str[i] == '-'){
        sign = -1;
        i++;
    }

    //From atoi: parse the integer part
    int result = 0;
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10.0 + (str[i] - '0');
        i++;
    }

    //Now, parse the fractional/decimal part
    double fraction = 1.0;
    if (str[i] == '.') {
        i++;
        while (str[i] >= '0' && str[i] <= '9') {
            result = result * 10.0 + (str[i] - '0');
            fraction *= 10.0;
            i++;
        }
    }

    return result * sign / fraction;
}

double add_constants() {
    double total = 0.0;
    FILE *file = fopen("q2.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return -1;
    }

    char buffer[200]; //Buffer to store each line
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        //printf("%s", buffer); 

        // Check for each ints and decimals
        char *ptr = buffer;
        while (*ptr != '\0') {
            if (*ptr >= '0' && *ptr <= '9') {
                double num = my_atof(ptr);
                // printf("%f\n", num);
                total += num;
                while (*ptr >= '0' && *ptr <= '9' || *ptr == '.') {
                    ptr++;
                }
            } else {
                ptr++;
            }
        }
    }
    fclose(file);
    return total;
}

// typedef struct student1{
//     char name[3];
//     int age;
// } student1;

// void change_name1_wrong(student1 s)
// {
//     s.name[0] = 'b';
// }

// void change_name1_right_a(student1 *p_s)
// {
//     p_s->name[0] = 'b';
// }

// void change_name1_right_b(student1 *p_s)
// {
//     strcpy(p_s->name, "b");
// }

int main() {
    printf("%f\n", add_constants());
}