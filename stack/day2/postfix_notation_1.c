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

int eval(char exp[]) {
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    CheckStack s;

    stackInit(&s);

    for (i = 0; i < len; i++) {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%') {
            value = ch - '0';
            push(&s, value);
        } else {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) {
            case '*':
                push(&s, op1 * op2); break;
            case '/':
                push(&s, op1 / op2); break;
            case '-':
                push(&s, op1 - op2); break;
            case '+':
                push(&s, op1 + op2); break;
            case '%':
                push(&s, op1 % op2); break;
            }
        }
    }
    return pop(&s);
}

int main(int argc, char const *argv[]) {
    int result;
    result = eval("82/3-32*+");
    printf("%d", result);
    return 0;
}
