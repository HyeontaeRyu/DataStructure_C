#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int i;
    char string[20];
} exer;

int main(int argc, char const *argv[]) {
    exer *a = (exer *)malloc(sizeof(exer));

    a -> i = 100;
    strcpy(a->string, "just testing");

    printf("%d, %s", a->i, a->string);

    free(a);

    return 0;
}
