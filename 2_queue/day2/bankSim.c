#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

typedef struct {
    int id;
    int arrivalTime;
    int serviceTime;
} element;

typedef struct {
    element *data;
    int rear, front, size, capacity;
} Queue;

void error(Queue *q, char *message) {
    fprintf(stderr, "%s\n", message);
    free(q->data);
    free(q);
    exit(1);
}

Queue* createQueue(int capacity) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = q->rear = q->size = 0;
    q->data = (element *)malloc(capacity * sizeof(element));
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

int isFull(Queue *q) {
    return q->size == q->capacity;
}

void enqueue(Queue *q, element e) {
    if (isFull(q)) 
        error(q, "큐가 포화 상태 입니다.");
    q->size++;
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = e;
}

element dequeue(Queue *q) {
    if (isEmpty(q))
        error(q, "큐가 공백 상태 입니다.");
    q->size--;
    q->front = (q->front + 1) % q->capacity;
    return q->data[q->front];
}

void printQueue(Queue *q) {
    printf("Queue (front = %d, rear = %d, size = %d)", q->front, q->rear, q->size);
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
    int minutes = 60;
    int totalWait = 0;
    int totalCustomers = 0;
    int serviceTime_1 = 0;
    int serviceTime_2 = 0;
    int serviceCustomer_1;
    int serviceCustomer_2;
    Queue *q = createQueue(6);
    srand(time(NULL));

    for (int clock = 0; clock < minutes; clock++) {
        printf("현재 시각 = %d\n", clock);
        if((rand()%10) < 3) {
            element customer;
            customer.id = totalCustomers++;
            customer.arrivalTime = clock;
            customer.serviceTime = rand() % 3 + 1;
            enqueue(q, customer);
            printf("고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n",
                customer.id, customer.arrivalTime, customer.serviceTime);
        }
        if(serviceTime_1 > 0) {
            printf("고객 %d 업무처리중입니다. \n", serviceCustomer_1);
            serviceTime_1--;
        } else {
            if (!isEmpty(q)) {
                element customer = dequeue(q);
                serviceCustomer_1 = customer.id;
                serviceTime_1 = customer.serviceTime;
                printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n", 
                    customer.id, clock, clock - customer.arrivalTime);
                totalWait += clock - customer.arrivalTime;
            }
        }
        if(serviceTime_2 > 0) {
            printf("고객 %d 업무처리중입니다. \n", serviceCustomer_2);
            serviceTime_2--;
        } else {
            if (!isEmpty(q)) {
                element customer = dequeue(q);
                serviceCustomer_2 = customer.id;
                serviceTime_2 = customer.serviceTime;
                printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n", 
                    customer.id, clock, clock - customer.arrivalTime);
                totalWait += clock - customer.arrivalTime;
            }
        }
    }
    printf("전체 대기 시간 %d분", totalWait);
    free(q->data);
    free(q);
    return 0;
}
