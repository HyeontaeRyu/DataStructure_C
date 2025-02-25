#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

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
    if (isFull(s)) {
        s->capacity *= 2;
        s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[++s->top] = e;
}

element pop(Stack *s) {
    if (isEmpty(s)) {
        fprintf(stderr, "Stack is Empty!");
        exit(1);
    }
    return s->data[s->top--];
}

element peek(Stack *s) {
    if (isEmpty(s)) {
        fprintf(stderr, "Stack is Empty!");
        exit(1);
    }
    return s->data[s->top];
}

int checkPalindrome(char *s) {
    Stack s1;
    initStack(&s1);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'z')
            push(&s1, tolower(s[i]));
    }
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'z') {
            if (pop(&s1) != tolower(s[i])) {
                free(s1.data);
             return 0;
            }
        }
    }
    free(s1.data);
    return 1;
}

int main(int argc, char const *argv[]) {
    char s[] = "madaM.";
    int isPalindrome = checkPalindrome(s);
    isPalindrome ? printf("회문입니다.") : printf("회문이 아닙니다.");
    return 0;
}
