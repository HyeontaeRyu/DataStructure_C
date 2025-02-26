#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct PersonTag {
    char name[10];
    int age;
    float salary;
} Person;

typedef struct {
    float real;
    float imaginary;
} complex;

complex AddComplex(complex a,  complex b) {
    complex r;

    r.real = a.real + b.real;
    r.imaginary = a.imaginary + b.imaginary;

    return r;
}

int main(int argc, char const *argv[])
{
    complex c1 = {3.1, 2};
    complex c2 = {4, 2.2};
    complex r = AddComplex(c1, c2);

    printf("%.1f + %.1fi", r.real, r.imaginary);

    return 0;
}
