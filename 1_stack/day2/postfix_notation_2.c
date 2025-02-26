#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef char element;
typedef struct {
    element *data;
    int capacity;
    int top;
} CheckStack;

void stackInit(CheckStack *s) {
    s->capacity = 1;
    s->top = -1;
    s->data = (element *)malloc(s->capacity * sizeof(element));
}

int isEmpty(CheckStack *s) {
    return (s->top) == -1;
}

int isFull(CheckStack *s) {
    return (s->top) == ((s->capacity) - 1);
}

void push(CheckStack *s, element input) {
    if (isFull(s)) {
        s->capacity *= 2;
        s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
    } 
    s->data[++(s->top)] = input;
}

element pop(CheckStack *s) {
    if (isEmpty(s)) {
        fprintf(stderr, "스택이 비어 있습니다.\n");
        exit(1);
    } else return s->data[(s->top)--];
}

element peek(CheckStack *s) {
    if (isEmpty(s)) {
        fprintf(stderr, "스택이 비어 있습니다.\n");
        exit(1);
    } else return s->data[(s->top)];
}

int prec(char c) {
    switch (c) {
        case '(': case ')': return 0;
        case '-': case '+': return 1;
        case '*': case '/': return 2;
    }
}

void toPostfix(char *c) {
    int len = strlen(c);
    char ch, top_op;
    CheckStack s;
    stackInit(&s);

    for (int i = 0; i < len; i++) {
        ch = c[i];
        switch (ch) {
            case '+': case '-': case '*': case '/': case '%':
                while (!isEmpty(&s) && (prec(ch) <= prec(peek(&s)))) 
                    printf("%c", pop(&s));
                push(&s, ch);
                break;
            case '(':
                push(&s, ch);
                break;
            case ')':
                top_op = pop(&s);
                while (top_op != '(') {
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
                break;
            default:
                printf("%c", ch);
                break;
        }
    }
    while (!isEmpty(&s)) {
        printf("%c", pop(&s));
    }
}

int main(int argc, char const *argv[]) {
    char *s = "4+5*(1+2/1)";
    toPostfix(s);
    
    return 0;
}
