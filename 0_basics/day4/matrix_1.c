#include <stdio.h>
#define ROWS 3
#define COLS 3

void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            B[j][i] = A[i][j];
        }
    }
}

void print_matrix(int A[ROWS][COLS]) {
    printf("==================\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("==================\n");
}

int main(void) {
    int array1[ROWS][COLS] = { {2, 3, 0}, 
                               {8, 9, 1}, 
                               {7, 0, 5} };
    int array2[ROWS][COLS];

    matrix_transpose(array1, array2);
    print_matrix(array1);
    print_matrix(array2);
    return 0;
}