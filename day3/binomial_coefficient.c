#include <stdio.h>

int memo[100][100] = {0};

int C(int n, int k) {
    if (k > n) return 0; // 이거 안하면 k가 n보다 클때 무한 재귀로 스택 오버플로우 발생. Segmentation Fault.
    if (k == n || k == 0) return 1;
    if ((memo[n][k])) return memo[n][k];
    memo[n][k] = C(n-1, k-1) + C(n-1, k);
    return memo[n][k];
}

int main() {
    printf("result : %d", C(3, 4));
}