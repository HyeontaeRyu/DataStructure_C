#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char c;
    int n;
} element;
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
    if (isFull(s)) {
        s->capacity *= 2;
        s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[++(s->top)] = e;
}

element pop(Stack *s) {
    if (isEmpty(s)) {
        fprintf(stderr, "Stack is Empty!");
        exit(1);
    }
    return s->data[(s->top)--];
}

element peek(Stack *s) {
    if (isEmpty(s)) {
        fprintf(stderr, "Stack is Empty!");
        exit(1);
    }
    return s->data[(s->top)];
}

Stack compressString(char *c) {
    Stack s;
    initStack(&s);
    char ch;
    int len = strlen(c);
    element tmp = {'\0', 0};

    for (int i = 0; i < len; i++) {
        ch = c[i];
        if (ch >= 'A' && ch <= 'Z') 
            ch = ch - 'A' + 'a';
        if (isEmpty(&s) || tmp.c != ch) {
            tmp.c = ch;
            tmp.n = 1;
            push(&s, tmp);
        } else if (s.data[s.top].c == ch) {
            tmp = pop(&s);
            tmp.n++;
            push(&s, tmp);
            tmp = peek(&s);
        }
    }

    return s;
}

void printCompressedString(Stack *s) {
    element tmp;
    Stack reversedStack;
    initStack(&reversedStack);
    while (!isEmpty(s)) {
        push(&reversedStack, pop(s));
    }
    while (!isEmpty(&reversedStack)) {
        tmp = pop(&reversedStack);
        printf("%d%c", tmp.n, tmp.c);
    }

    free(reversedStack.data);
}

int main(int argc, char const *argv[]) {
    printf("문자열을 입력하시오 : ");
    char c[100];
    scanf("%s", &c);
    Stack s = compressString(c);
    printCompressedString(&s);
    free(s.data);
    return 0;
}
