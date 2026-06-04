#include <stdio.h>

#define MAX_WORD 100

/*
============================================================
QUESTION 3. REVERSED CROSS WORD
Points: 2.5

Write a program that reads one word and prints it vertically and
horizontally so that the words intersect in the middle.

The horizontal word must be printed in reverse order.
Assume that the word length is odd.

Requirements:
- Do not use string.h.
- Write a function that calculates the length of a string.
- Use spaces to align the vertical word.
- The horizontal word must appear on the middle row.

Example input:
MANDARINO

Example output:
    M
    A
    N
    D
ONIRADNAM
    R
    I
    N
    O
============================================================
*/

int string_length(char s[]) {
    int len=0;
    while (s[len]!='\0'){
        len++;
    }
    return len;
}

int main(void) {
    char s[100];
    scanf("%s", s);

    int len=string_length(s);

    if (len%2==0){
        printf("The length of %s should be odd", s);
        return 0;
    }

    int mid=len/2;

    for (int i=0; i<len; i++){
        if (i!=mid){
            for (int j=0; j<mid; j++){
                printf(" ");
            }
            printf("%c", s[i]);
        }
        else{
            for (int k=len-1; k>=0; k--){
                printf("%c", s[k]);
            }
        }     
        printf("\n");   
    }
    return 0;
}
