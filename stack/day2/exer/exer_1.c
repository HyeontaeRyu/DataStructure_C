#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX 6
typedef int element;
typedef struct {
    element data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

int isFull(Stack *s) {
    return (s->top == (MAX - 1));
}

void push(Stack *s, element e) {
    if (isFull(s)) {
        fprintf(stderr, "Stack is Full!");
        exit(1);
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

int main(int argc, char const *argv[]) {
    Stack s;
    initStack(&s);
    int value;

    printf("정수 배열의 크기 : %d\n", MAX);
    printf("정수를 입력하시오 : ");
    for (int i = 0; i < MAX; i++) {
        scanf("%d", &value);
        push(&s, value);
    }

    printf("반전된 정수 배열 : ");
    for (int i = 0; i < MAX; i++)
        printf("%d ", pop(&s));

    return 0;
}
