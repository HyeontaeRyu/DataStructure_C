#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define SIZE 10

int power(int x, int n) {
    if (n == 0) return 1;
    else if (n < 0) return 1 * power(x, -n);

    int half = power(x, n/2);

    if (n % 2 == 0) return half * half;
    else return x * half * half;
}

void PrintArray(int *array) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
}

int main(int argc, char const *argv[]) {
    int *two;
    two = (int *)malloc(SIZE * sizeof(int));

    if (two == NULL) {
        fprintf(stderr, "메모리 할당에 실패했습니다.");
        exit(1);
    }

    for (int i = 0; i < SIZE; i++) {
        two[i] = power(2, i);
    }

    PrintArray(two);
    
    return 0;
}