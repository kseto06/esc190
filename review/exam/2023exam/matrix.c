
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
    int n;
    int m;
    int **matrix;
} Matrix;

int getElem(Matrix m, int i, int j) {
    return m.matrix[i][j];
}

void setElem(Matrix m, int i, int j, int elem) {
    m.matrix[i][j] = elem;
}

Matrix sum(Matrix matrix1, Matrix matrix2) {
    Matrix result;
    int m = matrix1.m, n = matrix1.n;
    result.m = m;
    result.n = n;
    result.matrix = (int **)malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++) {
        result.matrix[i] = (int *)malloc(n * sizeof(int));
    }

    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            result.matrix[row][col] = matrix1.matrix[row][col] + matrix2.matrix[row][col];
        }
    }

    return result;
}

void printMatrix(Matrix m) {
    for (int i = 0; i < m.m; i++) {
        for (int j = 0; j < m.n; j++) {
            printf("%d ", m.matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Matrix m1;
    m1.m = 2; 
    m1.n = 2; 

    m1.matrix = (int **)malloc(m1.m * sizeof(int *));

    for (int i = 0; i < m1.m; i++) {
        m1.matrix[i] = (int *)malloc(m1.n * sizeof(int));
    }

    m1.matrix[0][0] = 1;
    m1.matrix[0][1] = -1;
    m1.matrix[1][0] = 2;
    m1.matrix[1][1] = 0;

    Matrix m2;
    m2.m = 2; 
    m2.n = 2; 

    m2.matrix = (int **)malloc(m2.m * sizeof(int *));

    for (int i = 0; i < m2.m; i++) {
        m2.matrix[i] = (int *)malloc(m2.n * sizeof(int));
    }

    m2.matrix[0][0] = -1;
    m2.matrix[0][1] = 2;
    m2.matrix[1][0] = 0;
    m2.matrix[1][1] = 1;

    printf("%d\n", getElem(m1, 0, 0));
    printf("\n");

    Matrix res = sum(m1, m2);
    printMatrix(res);
    printf("\n");

    setElem(res, 0, 0, 69);
    printMatrix(res);
    return 0;
}
