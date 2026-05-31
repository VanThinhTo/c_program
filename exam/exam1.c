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
  
  if (argc != 2) {
    printf("Usage: %s word\n", argv[0]);
    return 1;
  }

  char *word = argv[1];
  
  int len=0;
  while (word[len]!='\0'){
    len++;
  }

  int mid=len/2;

  for (int i=0; i<len; i++){
    if (i==mid){
      for (int j=len-1; j>=0; j--){
        printf("%c",word[j]);
      }
      printf("\n");
    }
    else{
      for (int j=0; j<mid; j++){
        printf(" ");
      }
      printf("%c\n", word[i]);
    }
  }
  return 0;
}
