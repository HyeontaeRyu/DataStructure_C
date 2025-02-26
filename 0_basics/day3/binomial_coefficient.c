#include <stdio.h>

int memo[100][100] = {0};

int C(int n, int k) {
    if (k > n) return 0; // 이거 안하면 k가 n보다 클때 무한 재귀로 스택 오버플로우 발생. Segmentation Fault.
    if (k == n || k == 0) return 1;
    if (!(memo[n][k])) memo[n][k] = C(n-1, k-1) + C(n-1, k);
    return memo[n][k];
}

int IC(int n, int k) {
    if (k > n) return 0;
    int result = 1;
    int x = 1, y = 1, z = 1;
    for (int i = 1; i <= n; i++) x *= i;
    for (int i = 1; i <= k; i++) y *= i;
    for (int i = 1; i <= n-k; i++) z *= i;
    return x/(y*z);
}

int main() {
    printf("result : %d\n", C(4, 2));
    printf("result : %d", IC(4, 2));
}