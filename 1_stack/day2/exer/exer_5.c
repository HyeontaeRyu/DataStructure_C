#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef char element;
typedef struct {
    element *data;
    int capacity;
    int top;
    int size;
} Stack;

void initStack(Stack *s) {
    s->capacity = 1;
    s->top = -1;
    s->size = 0;
    s->data = (element *)malloc(s->capacity * sizeof(element));
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == (s->capacity - 1);
} 

void push(Stack *s, element e) {
    if(isFull(s)) {
        s->capacity *= 2;
        s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
    }
    s->size++;
    s->data[++(s->top)] = e;
}

element pop(Stack *s) {
    if(isEmpty(s)) {
        fprintf(stderr, "Stack is Empty!");
        exit(1);
    }
    s->size--;
    return s->data[(s->top)--];
}

element peek(Stack *s) {
    if(isEmpty(s)) {
        fprintf(stderr, "Stack is Empty!");
        exit(1);
    }
    return s->data[s->top];
}