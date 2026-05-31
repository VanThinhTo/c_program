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
    int first=1;
    int previous;
    int count=0;
    int max_count=0;

    while ((scanf("%d", &n)==1)){
        if (first){
            first=0;
            count++;
            max_count=count;
        }
        else{
            if (previous<n){
                count++;
                if (count > max_count){
                    max_count = count;
                }
            }
            else{
                if (count > max_count){
                    max_count = count;
                }
                count=1;
            }
        }
        previous=n;
    }

    printf("\n");
    printf("Max monotone length: %d", max_count);
}