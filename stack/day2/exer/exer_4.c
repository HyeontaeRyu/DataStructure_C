#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef char element;
typedef struct {
    element *data;
    int capacity;
    int top;
} Stack;

void initStack(Stack *s) {
    s->capacity = 1;
    s->top = -1;
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
    s->data[++(s->top)] = e;
}

element pop(Stack *s) {
    if(isEmpty(s)) {
        fprintf(stderr, "Stack is Empty!");
        exit(1);
    }
    return s->data[(s->top)--];
}

element peek(Stack *s) {
    if(isEmpty(s)) {
        fprintf(stderr, "Stack is Empty!");
        exit(1);
    }
    return s->data[s->top];
}

Stack deleteContinouslyDupNums(char *c) {
    Stack s, stmp;
    int len = strlen(c);
    char ch = '\0';
    initStack(&s);
    initStack(&stmp);
    for (int i = 0; i < len; i++) {
        ch = c[i];
        if(!(ch >= '0' && ch <= '9')) {
            fprintf(stderr, "Not Integer!");
            exit(1);
        } 
        if (isEmpty(&stmp) || peek(&stmp) != ch) {
            push(&stmp, ch);
        } 
    }
    while (!isEmpty(&stmp)) {
        push(&s, pop(&stmp));
    }
    free(stmp.data);
    return s;
}

void printStack(Stack *s) {
    while (!isEmpty(s)) {
        printf("%c", pop(s));
    }
}

int main(int argc, char const *argv[]) {
    char c[100];
    Stack s;
    printf("정수를 입력하세요 : ");
    scanf("%s", &c);
    s = deleteContinouslyDupNums(c);

    printf("출력 : ");
    printStack(&s);
    free(s.data);
    return 0;
}
