#include <stdio.h>

double IterativePower(double x, int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) 
        result = result * x;
    return result;
}

double RecursivePower(double x, int n) { 
    /* 
        O(log n) 의 시간복잡도를 가짐.
        x^n 에서 n이 1이 될때까지 절반으로 줄음.
        n/2 -> n/(2^2) -> n/(2^3) -> ... -> n/(2^k) = 1
        -> log n = k
        n 이 계속 절반으로 줄어들어 1이 될 때 까지 걸리는 시간은 log n
        즉 이 함수의 시간복잡도는 O(log n)
    */ 
    if (x == 0) return 1;
    if (x < 0) return 1/RecursivePower(x, -n);

    double half = RecursivePower(x, n/2);

    if (n % 2 == 0) return half * half;
    else return x * half * half;
}

int main(void) {
    double a = 5;
    int n = 3;

    printf("result : %f\n", RecursivePower(a, n));
    printf("result : %f", IterativePower(a, n));
}