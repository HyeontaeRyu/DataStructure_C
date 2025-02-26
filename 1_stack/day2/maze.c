#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAZE_SIZE 6

typedef struct {
    short r;
    short c;
} element;

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

element here = { 1, 0 }, entry = { 1, 0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
    { '1', '1', '1', '1', '1', '1' },
    { 'e', '0', '1', '0', '0', '1' },
    { '1', '0', '0', '0', '1', '1' },
    { '1', '0', '1', '0', '1', '1' },
    { '1', '0', '1', '0', '0', 'x' },
    { '1', '1', '1', '1', '1', '1' },
};

void pushLoc(CheckStack *s, int r, int c) {
    if (r < 0 || c < 0) return;
    if (maze[r][c] != '1' && maze[r][c] != '.') {
        element tmp;
        tmp.r = r;
        tmp.c = c;
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

int main(int argc, char const *argv[]) {
    int r, c;
    CheckStack s;

    stackInit(&s);
    here = entry;
    while (maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        printMaze(maze);
        pushLoc(&s, r-1, c);
        pushLoc(&s, r, c+1);
        pushLoc(&s, r+1, c);
        pushLoc(&s, r, c-1);
        if (isEmpty(&s)) {
            printf("실패!");
            exit(1);
        } else
            here = pop(&s);
    }
    printf("성공!");
    return 0;
}
