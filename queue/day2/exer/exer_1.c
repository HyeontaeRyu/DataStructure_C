#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct {
    element *data;
    int size, rear, front, capacity;
} Queue;

void error(Queue *q, char *message) {
    fprintf(stderr, "%s\n", message);
    free(q->data);
    free(q);
    exit(1);
}

Queue* createQueue(int capacity) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = q->rear = q->size = 0;
    q->data = (element *)malloc(q->capacity * sizeof(element));
    return q;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

int isFull(Queue *q) {
    return q->size == q->capacity;
}

void enqueue(Queue *q, element e) {
    if (isFull(q))
        error(q, "큐가 포화 상태 입니다.");
    q->size++;
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = e;
}

element dequeue(Queue *q) {
    if (isEmpty(q)) 
        error(q, "큐가 공백 상태 입니다.");
    q->size--;
    q->front = (q->front + 1) % q->capacity;
    return q->data[q->front];
}

element peek(Queue *q) {
    if (isEmpty(q))
        error(q, "큐가 공백 상태 입니다.");
    return q->data[(q->front + 1) % q->capacity];
}

int getCount(Queue *q) {
    return q->size;
}