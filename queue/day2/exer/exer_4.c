#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char element;
typedef struct {
    element *data;
    int size, capacity, rear, front;
} Deque;

void error(Deque *d, char *message) {
    fprintf(stderr, "%s\n", message);
    free(d->data);
    free(d);
    exit(1);
}

Deque* createDeque(int capacity) {
    Deque *d = (Deque *)malloc(sizeof(Deque));
    d->capacity = capacity + 1;
    d->front = d->rear = d->size = 0;
    d->data = (element *)malloc(d->capacity * sizeof(element));
    return d;
}

int isEmpty(Deque *d) {
    return d->size == 0;
}

int isFull(Deque *d) {
    return d->size == d->capacity - 1;
}

void addRear(Deque *d, element e) {
    if (isFull(d))
        error(d, "큐가 포화 상태입니다.");
    d->size++;
    d->rear = (d->rear + 1) % d->capacity;
    d->data[d->rear] = e;
}

void addFront(Deque *d, element e) {
    if (isFull(d))
        error(d, "큐가 포화 상태입니다.");
    d->size++;
    d->front = (d->front - 1 + d->capacity) % d->capacity;
    d->data[d->front] = e;
}

element removeFront(Deque *d) {
    if (isEmpty(d))
        error(d, "큐가 공백 상태입니다.");
    d->front = (d->front + 1) % d->capacity;
    d->size--;
    return d->data[d->front];
}

element removeRear(Deque *d) {
    if (isEmpty(d))
        error(d, "큐가 공백 상태입니다.");
    int prev = d->rear;
    d->rear = (d->rear - 1 + d->capacity) % d->capacity;
    d->size--;
    return d->data[prev];
}

int isPalindrome(char *input) {
    int len = strlen(input);
    char ch, f, r;
    Deque *d = createDeque(len);
    for (int i = 0; i < len; i++) {
        ch = tolower(input[i]);
        addRear(d, ch);
    }
    while (d->size > 1) {
        f = removeFront(d);
        r = removeRear(d);
        if (removeFront(d) != removeRear(d)) {
            free(d->data);
            free(d);
            return 0;
        }
    }
    free(d->data);
    free(d);
    return 1;
}

int main(int argc, char const *argv[]) {
    char input[] = "aBmaDaMba";
    if (isPalindrome(input))
        printf("회문입니다.");
    else
        printf("회문이 아닙니다.");
    return 0;
}
