#include <stdio.h>

/* 
Write a program that reads a word from the command line and prints it horizontally and vertically so that
the two obtained words intersect in the middle. 
The horizontal word must be printed in reverse order.
See the execution examples below. 
Assume that the typed word's length is odd.

$ ./a.out MANDARINO
    M
    A
    N
    D
ONIRADNAM
    R
    I
    N
    O

$ ./a.out bigne
  b
  i
engib
  n
  e 

*/

int main(int argc, char *argv[]){
    if (argc!=2){
        printf("InputError: Should have 2 argc!");
        return 0;
    }

    char *s = argv[1];

    int len=strlen(s);

    if (len%2==0){
        printf("The length of %s should be odd", argv[1]);
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
