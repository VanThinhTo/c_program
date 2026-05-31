#include <stdio.h>

int main(){
    int n;
    char ch;

    scanf("%d", &n);
    scanf(" %c", &ch);
    while (ch!='c'){
        scanf(" %c", &ch);
    }
    return 0;
}
