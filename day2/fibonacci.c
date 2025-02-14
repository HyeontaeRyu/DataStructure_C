#include <stdio.h>

#define MOD 1000000007

int RecursiveFib(int n) { // 같은 함수를 여러번 호출하게 되어 비효율적. O(2^n)
    if (n == 0) return 0;
    if (n == 1) return 1;
    return RecursiveFib(n - 1) + RecursiveFib(n - 2);
}

int IterativeFib(int n) { // O(n)의 시간복잡도를 가져 차라리 이게 나음.
    int a = 0;
    int b = 1;

    int result = 0;

    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }

    return result;
}

void multiplyMatrix(int A[2][2], int B[2][2]) {
    int temp[2][2];

    temp[0][0] = A[0][0] * B[0][0] + A[1][0] * B[0][1];
    temp[1][0] = A[0][0] * B[1][0] + A[0][1] * B[1][1];
    temp[]
}

int main(void) {
    int a = 10;

    printf("result = %d\n", RecursiveFib(a));
    printf("result = %d", IterativeFib(a));
    return 0;
}