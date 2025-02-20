#include <stdio.h>

void Hanoi(int n, char from, char tmp, char to) {
    if (n == 1) printf("원반 %d 를 %c 에서 %c 로 옮긴다.\n", n, from, to);
    else {
        Hanoi(n-1, from, to, tmp);
        printf("원반 %d 를 %c 에서 %c 로 옮긴다.\n", n, from, to);
        Hanoi(n-1, tmp, from, to);
    }
}

int main() {
    Hanoi(4, 'a', 'b', 'c');
}