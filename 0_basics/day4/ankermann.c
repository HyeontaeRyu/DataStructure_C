#include <stdio.h>

int Ankermann(int m, int n) {
    if ( m == 0 ) return n + 1; 
    else if ( n == 0 ) return Ankermann(m-1, 1); 
    else return Ankermann(m-1, Ankermann(m, n-1));
}

int main(void) {
    printf("%d\n", Ankermann(3,3));
    printf("%d", Ankermann(2,3));
}