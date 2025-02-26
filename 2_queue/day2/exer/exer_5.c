#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id, taskTime;
} element;

typedef struct {
    element *data;
    int rear, front, size, capacity;
} Deque;

typedef struct {
    Deque *d;
    int id, reservedTask, currentTaskTime; 
} CPU;

void error(Deque *d, char *message) {
    fprintf(stderr, "%s\n", message);
    free(d->data);
    free(d);
    exit(1);
}

Deque* createDeque(int capacity) {
    Deque *d = (Deque *)malloc(sizeof(Deque));
    d->capacity = capacity + 1;
    d->front = d->rear = d->size = 0;
    d->data = (element *)malloc(d->capacity * sizeof(element));

    return d;
}

CPU* createCPU(int id) {
    CPU *c = (CPU *)malloc(sizeof(CPU));
    c->d = createDeque(4);
    c->id = id;
    
    return c;
}

int isEmpty(Deque *d) {
    return d->size == 0;
}

int isFull(Deque *d) {
    return d->size == d->capacity - 1;
}

void addRear(Deque *d , element e) {
    if (isFull(d))
        error(d, "큐가 포화 상태 입니다.");
    d->size++;
    d->rear = (d->rear + 1) % d->capacity;
    d->data[d->rear] = e;
}

void addFront(Deque *d , element e) {
    if (isFull(d))
        error(d, "큐가 포화 상태 입니다.");
    d->size++;
    d->data[d->front] = e;
    d->front = (d->front - 1 + d->capacity) % d->capacity;
}

element deleteFront(Deque *d) {
    if (isEmpty(d))
        error(d, "큐가 비어 있습니다.");
    d->size--;
    d->front = (d->front + 1) % d->capacity;
    return d->data[d->front];
}

element deleteRear(Deque *d) {
    if (isEmpty(d))
        error(d, "큐가 비어 있습니다.");
    d->size--;
    int prev = d->rear;
    d->rear = (d->rear - 1 + d->capacity) % d->capacity;
    return d->data[prev];
}

element getFront(Deque *d) {
    if (isEmpty(d))
        error(d, "큐가 비어 있습니다.");
    return d->data[(d->front + 1) % d->capacity];
}

element getRear(Deque *d) {
    if (isEmpty(d))
        error(d, "큐가 비어 있습니다.");
    return d->data[d->rear];
}

void destoryDeque(Deque *d) {
    free(d->data);
    free(d);
}

void destroyCPU(CPU *c) {
    destoryDeque(c->d);
    free(c);
}

void startTask(CPU *c) {
    element task = deleteFront(c->d);
    c->reservedTask = task.id;
    c->currentTaskTime = task.taskTime;
    printf("%d번 시피유 %d번 작업 시작.\n", c->id, c->reservedTask);
}

int main(int argc, char const *argv[]) {
    int minutes = 60;
    int totalTask = 0;

    CPU *c1 = createCPU(1), *c2 = createCPU(2), *c3 = createCPU(3);
    srand(time(NULL));

    for (int clock = 0; clock < minutes; clock++) {
        printf("현재 시각 : %d\n", clock);
        if (rand() % 10 < 5) {
            element task;
            task.id = totalTask++;
            task.taskTime = rand() % 3 + 1;
            addRear(c1->d, task);
            printf("%d번 작업 생성, 작업량 : %d\n", task.id, task.taskTime);
        }

        // 1번 CPU.
        if (c1->currentTaskTime > 0) {
            printf("1번 시피유 %d번 작업 작업중. 남은 작업량 : %d\n", c1->reservedTask, c1->currentTaskTime);
            c1->currentTaskTime--;
        } else {
            if (!isEmpty(c1->d)) {
                startTask(c1);
            } else {
                if (!isEmpty(c2->d) && (getRear(c2->d).id != c2->reservedTask)) {
                    addRear(c1->d, deleteRear(c2->d));
                    printf("1번 시피유, 2번 시피유 Deque에서 %d번 작업 Steal.\n", getFront(c1->d));
                    startTask(c1);
                } else if (!isEmpty(c3->d) && (getRear(c3->d).id != c3->reservedTask)) {
                    addRear(c1->d, deleteRear(c3->d));
                    printf("1번 시피유, 3번 시피유 Deque에서 %d번 작업 Steal.\n", getFront(c1->d));
                    startTask(c1);
                }
            }
        }

        // 2번 CPU.
        if (c2->currentTaskTime > 0) {
            printf("2번 시피유 %d번 작업 작업중. 남은 작업량 : %d\n", c2->reservedTask, c2->currentTaskTime);
            c2->currentTaskTime--;
        } else {
            if (!isEmpty(c2->d)) {
                startTask(c2);
            } else {
                if (!isEmpty(c1->d) && (getRear(c1->d).id != c1->reservedTask)) {
                    addRear(c2->d, deleteRear(c1->d));
                    printf("2번 시피유, 1번 시피유 Deque에서 %d번 작업 Steal.\n");
                    startTask(c2);
                } else if (!isEmpty(c3->d) && (getRear(c3->d).id != c3->reservedTask)) {
                    addRear(c2->d, deleteRear(c3->d));
                    printf("2번 시피유, 3번 시피유 Deque에서 %d번 작업 Steal.\n");
                    startTask(c2);
                }
            }
        }

        // 3번 CPU.
        if (c3->currentTaskTime > 0) {
            printf("3번 시피유 %d번 작업 작업중. 남은 작업량 : %d\n", c3->reservedTask, c3->currentTaskTime);
            c3->currentTaskTime--;
        } else {
            if (!isEmpty(c3->d)) {
                startTask(c3);
            } else {
                if (!isEmpty(c1->d) && (getRear(c1->d).id != c1->reservedTask)) {
                    addRear(c3->d, deleteRear(c1->d));
                    printf("3번 시피유, 1번 시피유 Deque에서 %d번 작업 Steal.\n");
                    startTask(c3);
                } else if (!isEmpty(c2->d) && (getRear(c2->d).id != c1->reservedTask)) {
                    addRear(c1->d, deleteRear(c2->d));
                    printf("3번 시피유, 1번 시피유 Deque에서 %d번 작업 Steal.\n");
                    startTask(c3);
                }
            }
        }
    }

    destroyCPU(c1);
    destroyCPU(c2);
    destroyCPU(c3);
    return 0;
}
