#include <stdio.h>

/*
Simplified version of pra.c.

It reads the first value before the loop, so there is no need for a first flag.
Use n > previous for strictly increasing.
Use n >= previous for non-decreasing.
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

int main(){
    increase();
    return 0;
}
