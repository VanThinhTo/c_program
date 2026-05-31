#include<stdio.h>
/*
Write a program that calculates the first n values of Fibonacci's sequence, 
where n is a positive integer specified by the user.
The first two values are 1 1. The other values are obtained as sum of the two preceding values, 
that is, if n is greater than two:
fib(n) = fib(n-1) + fib(n-2)
*/

void fibonacci(void){
    printf("First n values of Fibonacci's sequence\n");
    printf("n: ");
    unsigned n;
    scanf("%u", &n);
    int fibo_1 = 0, fibo_2 = 1;

    if (n<=0){
        return;
    }
    
    printf("1 ");

    for (int i=2; i<=n;i++){
        int temp;
        temp = fibo_1 + fibo_2;
        printf("%d ", temp);           
        fibo_1 = fibo_2;
        fibo_2 = temp;
    }
}

//recursion
int fibo(int n){
    if (n<=0){
        return 0;
    }
    else{
        //base case
        if (n<=2){
            return 1;
        }
        //recursive
        else{
            return fibo(n-1)+fibo(n-2);
        }
    }
}