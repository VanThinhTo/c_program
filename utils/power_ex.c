#include<stdio.h>

/* 26 Mar 2026
Write a program that calculates b raised to the n, where b and n are a double and an integer, respectively, specified by the user.
*/

double power(float base, unsigned n){
    double power=1.0;
    for (int i = 1; i<=n; i++){
        power *= base;
    };
    return power;
}

int main(){
    float base;
    printf("base: ");
    scanf("%f", &base);
    
    unsigned n;
    printf("exponent: ");
    scanf("%u", &n);

    printf("%f", power(base, n));
    return 0;
}












