#include <stdio.h>
#include <stdlib.h>

#define MAX 7

typedef int element;
typedef struct {
    element data[MAX];
    int front;
    int rear;
} Queue;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue *q) {
    if (q->front == q->rear) 
        return 1;
    else 
        return 0;
}

int isFull(Queue *q) {
    if(q->rear == (MAX - 1)) 
        return 1;
    else 
        return 0;
}

void queuePrint(Queue *q) {
    printf("QUEUE(front = %d, rear = %d) ", q->front, q->rear);

    if(!isEmpty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

void enqueue(Queue *q, element e) {
    if (isFull(q)) 
        error("큐가 포화 상태입니다.");
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = e;
}

element dequeue(Queue *q) {
    if (isEmpty(q))
        error("큐가 비어있습니다.");
    q->front = (q->front + 1) % MAX;
    return q->data[q->front];
}

element peek(Queue *q) {
    if (isEmpty(q))
        error("큐가 비어있습니다.");
    return q->data[(q->front + 1) % MAX];
}

int main(int argc, char const *argv[]) {
    Queue q;
    int element;

    initQueue(&q);
    while (!isFull(&q)) {
        printf("정수를 입력하세요.");
        scanf("%d", &element);
        enqueue(&q, element);
        queuePrint(&q);
    }
    printf("큐는 포화상태 입니다.\n\n");

    while (!isEmpty(&q)) {
        element = dequeue(&q);
        printf("꺼내진 원소 : %d ", element);
        queuePrint(&q);
    }
    printf("큐는 공백상태 입니다.");
    
    return 0;
}
