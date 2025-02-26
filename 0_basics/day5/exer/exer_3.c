#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define N 15

int items = 10;

void insert(int arr[], int loc, int value) {
    for (int i = items; i > loc; i--) {
        arr[i] = arr[i - 1];
    }
    arr[loc] = value;
    items++;
}

void delete(int arr[], int loc) {
    items--;
    for (int i = loc; i < items; i++) {
        arr[i] = arr[i+1];
    }
}

int main(int argc, char const *argv[]) {
    int arr[N];

    for (int i = 0; i < items; i++) 
        arr[i] = i;

    insert(arr, 4, 10);
    for (int i = 0; i < items; i++)
        printf("%d ", arr[i]);
    printf("\n");

    delete(arr, 5);
    for (int i = 0; i < items; i++)
        printf("%d ", arr[i]);

    return 0;
}
