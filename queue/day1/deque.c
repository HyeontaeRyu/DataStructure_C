#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
    element *data;
    int rear, front, size, capacity;
} Deque;

void error(Deque *d, char *message) {
    fprintf(stderr, "%s\n", message);
    free(d->data);
    free(d);
}

Deque* createDeque(int capacity) {
    Deque *d = (Deque *)malloc(sizeof(Deque));
    d->capacity = capacity;
    d->front = d->rear = d->size = 0;
    d->data = (element *)malloc(capacity * sizeof(element));
    return d;
}

int isEmpty(Deque *d) {
    return d->front == d->rear;
}

int isFull(Deque *d) {
    return d->size == d->capacity;
}

void dequePrint(Deque *d) {
    printf("Deque(front = %d, rear = %d)", d->front, d->rear);
    if (!isEmpty(d)) {
        int i = d->front;
        do {
            i = (i + 1) % d->capacity;
            printf("%d | ", d->data[i]);
            if (i == d->rear)
                break;
        } while (i != d->front);
        printf("\n");
    }
}

void addRear(Deque *d, element e) {
    if (isFull(d)) 
        error(d, "덱이 포화 상태입니다.");
    d->rear = (d->rear + 1) % d->capacity;
    d->data[d->rear] = e;
}

element deleteFront(Deque *d) {
    if (isEmpty(d)) 
        error(d, "덱이 비어 있습니다.");
    d->front = (d->front + 1) % d->capacity;
    return d->data[d->front];
}

element getFront(Deque *d) {
    if (isEmpty(d))
        error(d, "덱이 비어 있습니다.");
    return d->data[(d->front + 1) % d->capacity];
}

void addFront(Deque *d, element e) {
    if (isFull(d)) 
        error(d, "덱이 포화 상태입니다.");
    d->data[d->front] = e;
    d->front = (d->front - 1 + d->capacity) % d->capacity;
}

element deleteRear(Deque *d) {
    int prev = d->rear;
    if (isEmpty(d))
        error(d, "덱이 비어 있습니다.");
    d->rear = (d->rear - 1 + d->capacity) % d->capacity;
    return d->data[prev];
}

element getRear(Deque *d) {
    if (isEmpty(d))
        error(d, "덱이 비어 있습니다.");
    return d->data[d->rear];
}

int main(void) {
    Deque *d = createDeque(5);

    for (int i = 0; i < 3; i++) {
        addFront(d, i);
        dequePrint(d);
    }
    for (int i = 0; i < 3; i++) {
        deleteFront(d);
        dequePrint(d);
    }

    free(d->data);
    free(d);
    return 0;
}