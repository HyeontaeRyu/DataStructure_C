#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAZE_SIZE 6

typedef struct {
    int r;
    int c;
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

element here = { 1, 0 }, entry = { 1, 0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
    { '1', '1', '1', '1', '1', '1' },
    { 'e', '0', '1', '0', '0', '1' },
    { '1', '0', '0', '0', '1', '1' },
    { '1', '0', '1', '0', '1', '1' },
    { '1', '0', '1', '0', '0', 'x' },
    { '1', '1', '1', '1', '1', '1' },
};

void pushLoc(Stack *s, int r, int c) {
    if (r < 0 || c < 0) return;
    if (maze[r][c] != '1' && maze[r][c] != '.') {
        element tmp;
        tmp.c = c;
        tmp.r = r;
        push(s, tmp);
    }
}

void printMaze(char maze[MAZE_SIZE][MAZE_SIZE]) {
    printf("\n");
    for (int r = 0; r < MAZE_SIZE; r++) {
        for (int c = 0; c < MAZE_SIZE; c++) {
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

element move(Stack *s, Stack *routeTrace) {
    push(routeTrace, pop(s));
    return peek(routeTrace);
}

int main(int argc, char const *argv[]) {
    int r, c;
    Stack s, routeTrace, tmp;


    initStack(&s);
    initStack(&routeTrace);
    initStack(&tmp);
    here = entry;
    while (maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        printMaze(maze);
        pushLoc(&s, r-1, c);
        pushLoc(&s, r+1, c);
        pushLoc(&s, r, c-1);
        pushLoc(&s, r, c+1);
        if (isEmpty(&s)) {
            fprintf(stderr, "실패!");
            exit(1);
        } else 
            here = move(&s, &tmp);
    }
    while (!isEmpty(&tmp)) {
        push(&routeTrace, pop(&tmp));
    }
    while (!isEmpty(&routeTrace)) {
        element etmp = pop(&routeTrace);
        printf("(%d, %d) ", etmp.r, etmp.c);
    }
    

    free(s.data);
    free(routeTrace.data);
    free(tmp.data);
    printf("\n성공!");
    return 0;
}
