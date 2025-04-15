
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int in_visited(char *str, char **visited, int visited_count) {
    for (int i = 0; i < visited_count; i++) {
        if (strcmp(str, visited[i]) == 0) {
            return 0;
        }
    }

    return -1;
}

int repeats(char **strs, int strs_sz) {
    char **visited = (char **)malloc(strs_sz * 3 * sizeof(char *));
    int repeated = 0;
    int visited_count = 0;

    for (int i = 0; i < strs_sz; i++) {
        if (in_visited(strs[i], visited, visited_count) == 0) {
            repeated++;
        } else {
            visited[i] = (char *)malloc(strlen(strs[i]) + 1);
            strcpy(visited[i], strs[i]);
            visited_count++;
        }
    }

    return repeated;
}

int main() {
    char *strs1[] = {"ESC", "MAT", "MSE", "CIV"};
    printf("%d\n", repeats(strs1, 4)); // 0

    char *strs2[] = {"ESC", "MAT", "MSE", "CIV", "ESC"};
    printf("%d\n", repeats(strs2, 5)); // 1
}
