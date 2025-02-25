#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];
} Queue;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void initQueue(Queue *q) {
    q->rear = -1;
    q->front = -1;
} 

void queuePrint(Queue *q) {
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        if (i <= q->front || i > q->rear) 
            printf("   | ");
        else 
            printf("%d | ", q->data[i]);
    }
    printf("\n");
}

int isFull(Queue *q) {
    if (q->rear == MAX_QUEUE_SIZE - 1) 
        return 1;
    else
        return 0;
}

int isEmpty(Queue *q) {
    if (q->rear == q->front) 
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, element e) {
    if (isFull(q)) {
        error("큐가 포화상태 입니다.");
        return;
    }
    q->data[++q->rear] = e;
}

element dequeue(Queue *q) {
    if (isEmpty(q)) {
        error("큐가 비어 있습니다.");
    }
    return q->data[++q->front];
}

int main(int argc, char const *argv[]) {
    int item = 0;
    Queue q;

    initQueue(&q);

    enqueue(&q, 10); queuePrint(&q);
    enqueue(&q, 20); queuePrint(&q);
    enqueue(&q, 30); queuePrint(&q);
    enqueue(&q, 40); queuePrint(&q);

    dequeue(&q); queuePrint(&q);
    dequeue(&q); queuePrint(&q);
    dequeue(&q); queuePrint(&q);
    dequeue(&q); queuePrint(&q);
    return 0;
}
