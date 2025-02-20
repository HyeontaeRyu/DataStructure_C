#include <stdio.h>

typedef struct studentTag {
    char name[10];
    int age;
    double gpa;
} student;

int main() {
    student a = {"kim", 20, 4.3};
    
    return 0;
}