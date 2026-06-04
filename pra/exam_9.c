#include <stdio.h>

/*
============================================================
QUESTION 9. RECURSIVE PASCAL TRIANGLE AND COMBINATIONS
Points: 3

Write a program that reads a positive integer n and prints Pascal's
Triangle with n rows.

Requirements:
- Create a recursive function unsigned long long combination(int n, int r).
- Use this rule:
  C(n, r) = 1, if r == 0 or r == n
  C(n, r) = C(n - 1, r - 1) + C(n - 1, r), otherwise
- Print the triangle with leading spaces so it has a triangle shape.
- If n <= 0, print "Invalid input".

Example input:
5

Example output:
        1
      1   1
    1   2   1
  1   3   3   1
1   4   6   4   1
============================================================
*/

unsigned long long combination(int n, int r) {
    //base case
    if (r==0 || n==r){
      return 1;
    }
    //recursive
    return combination(n-1,r-1)+combination(n-1, r);
}

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++){
      for (int k=0; k<(n-i-1); k++){
        printf("  ");
      }
      
      for (int j=0; j<=i; j++){
        printf("%4llu", combination(i, j));
      }
      printf("\n");
    }
    return 0;
}
