#include <stdio.h>

int RecursiveFactorial(int n){
    if (n<=1) return 1;
    else return n*RecursiveFactorial(n-1);
}

int IterativeFactorial(int n){
    int r = n;
    for (n; n > 1; n--) 
        r = r * (n-1); 
    return r;
}

int main(void){
    int a = 150;

    int b = RecursiveFactorial(a);
    printf("result : %d\n", b);

    b = IterativeFactorial(a);
    printf("result : %d", b);
    return 0;
}