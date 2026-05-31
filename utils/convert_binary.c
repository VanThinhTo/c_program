// convert an integer to its binary form
#include <stdio.h>

void convertBinary(unsigned n){
    char binary[32];
    int len=0;

    while (n!=0){
        binary[len]=n%2;
        n = n/2;
        len++;
    }

    for (int i=len-1; i>=0; i--){
        printf("%d", binary[i]);
    }
}
