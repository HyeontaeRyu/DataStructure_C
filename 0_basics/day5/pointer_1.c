#include <stdio.h>

void swap(int *px, int *py) {
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

int main(int argc, char const *argv[])
{
    int a = 1;
    int b = 2;
    swap(&a, &b);
    printf("%d, %d", a, b);
    return 0;
}