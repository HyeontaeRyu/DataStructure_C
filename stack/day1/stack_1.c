#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {
    int studentNo;
    char name[MAX_STRING];
    char address[MAX_STRING];
} element;

typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} Stack;

void stackInit(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

int isFull(Stack *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(Stack *s, element item) {
    if (isFull(s)) {
        fprintf(stderr, "스택이 가득 찼습니다.\n");
        return;
    } else {
        s->stack[++(s->top)] = item;
    }
}

element pop(Stack *s) {
    if (isEmpty(s)) {
        fprintf(stderr, "스택이 비어 있습니다.\n");
        exit(1);
    } else {
        return s->stack[(s->top)--];
    }
}

element peek(Stack *s) {
    if (isEmpty(s)) {
        fprintf(stderr, "스택이 비어 있습니다.\n");
        exit(1);
    } else {
        return s->stack[s->top];
    }
}

int main(void) {
    Stack *s;
    s = (Stack *)malloc(sizeof(Stack));

    stackInit(s);

    element ie = { 20010111, "Hong", "Japan" };
    element oe;

    push(s, ie);
    oe = pop(s);

    printf("학번 : %d\n", oe.studentNo);
    printf("성명 : %s\n", oe.name);
    printf("거주지 : %s", oe.address);

    free(s);

    return 0;
}