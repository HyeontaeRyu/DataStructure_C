#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef int element;
typedef struct {
    element *data;
    int capacity;
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (int *)malloc(s->capacity * sizeof(element));
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

int isFull(Stack *s) {
    return (s->top == (s->capacity - 1));
}

void push(Stack *s, element e) {
    if (isFull(s)) {
        s->capacity *= 2;
        s->data = (int *)realloc(s->data, s->capacity * sizeof(element));
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
    return s->data[s->top];
}

void braketNumPrint(char *c) {
    char ch;
    int len = strlen(c);
    int n = 0;
    Stack s;

    initStack(&s);

    for (int i = 0; i < len; i++) {
        ch = c[i];
        if(ch == '(') {
            printf("%d ", ++n);
            push(&s, n);
        } else if (ch == ')') {
            printf("%d ", pop(&s));
            n--;
        }
    }
    free(s.data);
}

int main(int argc, char const *argv[]){
    printf("수식 : ((((())(()))\n");
    char c[] = "((((())(()))";
    printf("괄호 깊이 : ");
    braketNumPrint(c);
    return 0;
}
