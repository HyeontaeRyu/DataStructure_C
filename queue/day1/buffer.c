#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct {
    int *data;
    int capacity, rear, front, size;
} Queue;

void error(Queue *q, char *message) {
    fprintf(stderr, "%s\n", message);
    free(q->data);
    free(q);
    exit(1);
}

Queue* createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = queue->size = 0;
    queue->data = (element *)malloc(capacity * sizeof(element));
    return queue;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

int isFull(Queue *q) {
    return q->size == q->capacity;
}

void enqueue(Queue *q, element e) {
    if (isFull(q)) {
        error(q, "큐가 포화 상태 입니다.");
    }
    q->size++;
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = e;
}

element dequeue(Queue *q) {
    if (isEmpty(q)) {
        error(q, "큐가 비어 있습니다.");
    }
    q->size--;
    q->front = (q->front + 1) % q->capacity;
    return q->data[q->front];
}

element peek(Queue *q) {
    if (isEmpty) {
        error(q, "큐가 비어 있습니다.");
    }
    return q->data[(q->front + 1) % q->capacity];
}

void printQueue(Queue *q) {
    printf("Queue(front = %d, rear = %d) ", q->front, q->rear);
    if (!isEmpty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % q->capacity;
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    Queue *q = createQueue(7);
    int element;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        if (rand() % 5 == 0) {
            enqueue(q, rand()%100);
            printQueue(q);
        }
        if (rand() % 10 == 0) { 
            dequeue(q);
            printQueue(q); 
        }
    }

    free(q->data);
    free(q);
    return 0;
}
