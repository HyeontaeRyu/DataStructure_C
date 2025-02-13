#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    clock_t start = clock();

    for (int i = 0; i < 1000; i++) {
        for (int i = 0; i < 1000; i++)
        {
            printf("Hello, World!\n");
        }
    }

    clock_t end = clock();

    double duration = (double)(end-start) / CLOCKS_PER_SEC;
    printf("Duration: %f\n", duration);
    return 0;
}