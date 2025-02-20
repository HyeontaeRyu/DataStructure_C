#include <stdio.h>
#define SIZE 6

void GetIntegers(int list[]) {
    printf("6개의 정수를 입력해 주세요 : ");
    for(int i = 0; i < SIZE; i++) 
        scanf("%d", &list[i]);
}

int SumCal(int list[]) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) 
        sum += list[i];
    return sum;
}

int main(int argc, char const *argv[]) {
    int list[SIZE];
    GetIntegers(list);
    printf("합 = %d", SumCal(list));
    return 0;
}