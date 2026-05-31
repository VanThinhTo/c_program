#include <stdio.h>

/*
Write a program that reads and arbitrary sequence of integers and calculates 
the length of the largest subsequence of increasing values.
For example, if the input sequence is
-1 -2 3 4 7 0 1 2
then the output is: 4
*/

void increase(void){
    int n;
    int previous;
    int count=1;
    int max_count=1;

    if (scanf("%d", &previous)!=1){
        printf("No input\n");
        return;
    }

    while (scanf("%d", &n)==1){
        if (n>=previous){
            count++;
        }
        else{
            count=1;
        }

        if (count>max_count){
            max_count=count;
        }

        previous=n;
    }

    printf("Max monotone length: %d\n", max_count);
}