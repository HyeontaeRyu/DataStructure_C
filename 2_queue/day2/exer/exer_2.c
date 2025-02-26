#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct {
    element *data;
    int size, top, capacity;
} Stack;

typedef struct {
    Stack *s1, *s2;
    int size;
} Queue;

void stackError(Stack *s, char *message) {
    fprintf(stderr, "%s\n", message);
    free(s->data);
    free(s);
    exit(1);
}

void queueError(Queue *q, char *message) {
    fprintf(stderr, "%s\n", message);
    free(q->s1->data);
    free(q->s2->data);
    free(q->s1);
    free(q->s2);
    free(q);
    exit(1);
}

Stack* createStack(int capacity) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->capacity = capacity;
    s->top = -1;
    s->size = 0;
    s->data = (element *)malloc(capacity * sizeof(element));
    return s;
}

Queue* createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->s1 = createStack(1);
    q->s2 = createStack(1);
    q->size = 0;
    return q;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

int isStackFull(Stack *s) {
    return s->top == s->capacity - 1;
}

int isQueueEmpty(Queue *q) {
    return q->size == 0;
}

void push(Stack *s, element e) { 
    if (isStackFull(s)) {
        s->capacity *= 2;
        s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
    }
    s->size++;
    s->data[++(s->top)] = e;
}

element pop(Stack *s) {
    if (isStackEmpty(s)) 
        stackError(s, "스택이 비어 있습니다.");
    s->size--;
    return s->data[(s->top)--];
}

void enqueue(Queue *q, element e) {
    q->size++;
    push(q->s1, e);
}

element dequeue(Queue *q) {
    if (isStackEmpty(q->s2)) {
        while (!isStackEmpty(q->s1)) {
            push(q->s2, pop(q->s1));
        }
    }
    q->size--;
    return pop(q->s2);
}