#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
    element *data;
    int capacity;
    int top;
} Stack;

void stackInit(Stack *s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc(s->capacity * sizeof(element));
}

int isEmpty(Stack *s) {
    return ((s->top) == -1);
}

int isFull(Stack *s) {
    return ((s->top) == (s->capacity-1));
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
        fprintf(stderr, "스택이 비어있습니다.\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(Stack *s) {
    if (isEmpty(s)) {
        fprintf(stderr, "스택이 비어있습니다.\n");
        exit(1);
    }
    else return s->data[(s->top)];
}

int main(int argc, char const *argv[]) {
    Stack s;
    stackInit(&s);
    
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));

    free(s.data);

    return 0;
}
