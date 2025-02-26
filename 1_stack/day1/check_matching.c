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

int checkMatching(const char *c) {
    CheckStack s;
    char ch, openCh;
    int i, n = strlen(c);
    stackInit(&s);

    for (i = 0; i < n; i++) {
        ch = c[i];
        switch (ch) {
        case '(': case '{': case '[':
            push(&s, ch);
            break;
        case ')': case '}': case ']':
            if (isEmpty(&s)) return 0;
            else {
                openCh = pop(&s);
                if ((openCh == '(' && ch != ')') || 
                    (openCh == '{' && ch != '}') || 
                    (openCh == '[' && ch != ']')) return 0;
            }
            break;
        }
    }
    if (!isEmpty(&s)) return 0;
    return 1;
} 

int main(int argc, char const *argv[]) {
    char *p = "{ A[(i+1)] = 0; }";
    if (checkMatching(p) == 1)
        printf("%s 괄호 검사 성공.", p);
    else 
        printf("%s 괄호 검사 실패.", p);
    return 0;
}
