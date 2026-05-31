/*
============================================================
EXERCISE 1. COMBINATION AS A FUNCTION
============================================================

Question:
Write a complete C program that reads two integers, n and r, and prints
the combination value C(n, r).

Requirements:
- Create a function that calculates factorial.
- Create a function that calculates combination.
- The combination formula is:
  C(n, r) = n! / (r! * (n - r)!)
- Read n and r from standard input.
- Check that the input is valid: 0 <= r <= n.
- Print an error message if the input is invalid.
- Print the final combination result.

Example input:
5 3

Example output:
C(5, 3) = 10
*/
#include <stdio.h>

unsigned long long factorial(int n){
  if (n<0){
    printf("ValueError: %d must be greater than 0\n", n);
    return 0;
  }

  if (n==0){
    return 1;
  }
  else
    return n*factorial(n-1);
}

unsigned long long combination(int n, int r){
  return factorial(n)/(factorial(r)*factorial(n-r));
}

int main(){
  int n;
  int r;

  if (scanf("%d %d", &n, &r)!=2){
    printf("Invalid input\n");
    return 0;
  }

  if ((0<=r) && (r<=n)){
    printf("C(%d, %d) = %llu", n, r, combination(n, r));
    return 1;
  }
  else{
    printf("ValueError: must be 0<=r<=n");
    return 0;
  }
}

/*
Mark: 8/10

Comment:
Good improvement: combination now returns a value through a structure, and the
result uses unsigned long long. The program still calculates the sample case
correctly and keeps the main validation condition 0 <= r <= n.

To improve it, add braces around the else block because the current indentation
causes a compiler warning. For invalid input, main still prints C(n, r) = 0 after
the error message, so return a status or handle invalid input before printing the
final result. Also check whether scanf successfully reads two integers and add a
newline after the final output.
*/
