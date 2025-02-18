#include <stdio.h>
#define MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
} element;

typedef struct SparseMatrix {
    element data[MAX_TERMS];
    int rows;
    int cols;
    int terms;
} SparseMatrix;

SparseMatrix matrix_transpose(SparseMatrix a) {
    SparseMatrix b;

    int bindex = 0;
    b.cols = a.rows;
    b.rows = a.cols;
    b.terms = a.terms;
    
    for (int i = bindex; i < a.terms; i++) {
        
    }
    
}