//define strcat from scratch
#include <stdio.h>
#include <string.h>

char * strconcat(char s1[], char s2[]){
    int len_s1=0;

    while (s1[len_s1]!='\0'){
        len_s1++;
    }

    int len_s2=0;

    while (s2[len_s2]!='\0'){
        len_s2++;
    }

    for (int i=0; i<len_s2; i++){
        s1[len_s1+i]=s2[i];
    }

    s1[len_s1 + len_s2] = '\0';

    return s1;
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}

// int main(){
//     char s1[100] = "hello ";
//     char s2[]="world";
    
//     strconcat(s1, s2);
//     // s1[6] = s2[0];
//     printf("%s\n", s1);
//     return 0;
// }