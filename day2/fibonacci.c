#include <stdio.h>

#define MOD 1000000007

int memo[100] = {1,1};

// 동적 계획법 (Dynamic Programming) 사용.
int DPFib(int n) {
    if (n<2) return n;
    if ((memo[n])) return memo[n];
    memo[n] = DPFib(n-1) + DPFib(n-2);
    return memo[n];
}

// 같은 함수를 여러번 호출하게 되어 비효율적. O(2^n)
int RecursiveFib(int n) { 
    if (n == 0) return 0;
    if (n == 1) return 1;
    return RecursiveFib(n - 1) + RecursiveFib(n - 2);
}

// O(n)의 시간복잡도로 이게 차라리 나음.
int IterativeFib(int n) { 
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

// 분할 정복을 활용한 알고리즘으로 행렬의 제곱으로 표현, 시간복잡도는 O(log n).
void MultiplyMatrix(int A[2][2], int B[2][2]) {
    int result[2][2];

    result[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    result[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    result[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    result[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;

    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < 2; j++)
            A[i][j] = result[i][j];
}

void PowerMatrix(int A[2][2], int n) {
    int I[2][2] = {1,0,0,1};
    if (n == 0) {
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < 2; j++)
                A[i][j] = I[i][j]; // == return 1
        return;
    }
    int base[2][2] = {1,1,1,0}; // 이걸 안 쓸 순 없을까..?

    PowerMatrix(A, n/2);

    MultiplyMatrix(A, A);

    if (n % 2 == 1)
        MultiplyMatrix(A, base);
}

int DivideFib(int n) {
    int A[2][2] = {1,1,1,0};

    PowerMatrix(A, n-1);

    return A[0][0];
}

int main(void) {
    int a = 10;

    printf("result = %d\n", RecursiveFib(a));
    printf("result = %d\n", IterativeFib(a));
    printf("result = %d\n", DPFib(a));
    printf("result = %d", DivideFib(a));
    return 0;
}