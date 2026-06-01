#include<stdio.h>
/*
Write a program that calculates the first n prime numbers, 
where n is a positive integer specified by the user.
For example, if n is 6 then the output is:
2 3 5 7 11 13
*/

int is_prime(unsigned n){
    
    if (n<2){
        return 0;
    }
    else if (n==2){
        return 1;
    }
    else if (n%2==0){
        return 0;
    }

    for (int i=3; i<=n/i; i+=2){
        if (n%i == 0){
            return 0;
        }
    }

    return 1;
}

// a is prime if cannot be divided by a number <= square root of a


void prime(void){
    printf("N prime numbers: ");
    int n;
    scanf("%d", &n);

    int count=0, number = 2;

    while (count < n)
    {
        if (is_prime(number)){
            printf("%d ", number);
            count ++;
        }
        number ++;
    }
    printf("\n");
}