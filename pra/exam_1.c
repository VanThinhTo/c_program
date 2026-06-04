#include <stdio.h>

/*
============================================================
QUESTION 1. FIRST PRIME NUMBERS AND THEIR SUM
Points: 2

Write a complete C program that reads a positive integer n and prints:
1. the first n prime numbers
2. the sum of those prime numbers

Requirements:
- Create a function int is_prime(unsigned n).
- Create a function that prints the first n prime numbers.
- Use loops, not arrays.
- If n <= 0, print "Invalid input".

Input:
One integer n.

Example input:
6

Example output:
2 3 5 7 11 13
Sum: 41
============================================================
*/

int is_prime(unsigned n) {
    if (n<2){
        return 0;
    }

    if (n==2){
        return 1;
    }

    if (n%2==0){
        return 0;
    }

    for (int i=2; i<n/2; i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(void) {
    unsigned n;
    scanf("%u", &n);

    if (n<=0){
        printf("Invalid input");
        return 1;
    }

    int count=0;
    int integer=2;
    int sum=0;

    while (count<n){
        if (is_prime(integer)){
            printf("%d ", integer);
            sum+=integer;
            count++;
        }
        integer++;
    }

    printf("\n");
    printf("Sum: %d\n", sum);

    return 0;
}
