/*
============================================================
EXERCISE 2. PASCAL TRIANGLE AS A SHAPE
============================================================

Question:
Write a complete C program that reads a positive integer n and prints
Pascal's Triangle with n rows.

Requirements:
- Read the number of rows from standard input.
- Use nested loops to print the triangle.
- Print each row on a new line.
- Add leading spaces so the output looks like a triangle shape.
- Each value in the triangle must follow Pascal's Triangle rules:
  - The first and last value in each row is 1.
  - Every other value is the sum of the two values above it.
- You may use a combination function if you want.

Example input:
5

Example output:
        1
      1   1
    1   2   1
  1   3   3   1
1   4   6   4   1
*/

/*
recursive
base case: P(r, 0) = P(r, r) = 1;
recursive formula: P(r, c) = P(r-1,c-1)+P(r-1,c)
*/
#include<stdio.h>

int pascal(int row, int col){
  if ((col==0) || (row==col)){
    return 1;
  }
  return (pascal(row-1, col-1)+pascal(row-1, col));
}

void pascalTriangle(int n){
  for (int i=0; i<n; i++){
    
    for (int k=0; k<n-i-1; k++){
      printf("  ");
    }
    
    for (int j=0; j<=i; j++){
      printf("%d   ", pascal(i, j));
    }
    printf("\n");
  }
}

int main(){
  int n;
  scanf("%d", &n);
  pascalTriangle(n);
  return 0;
}

/*
Mark: 8.5/10

Comment:
Good solution. It compiles without warnings, uses recursion correctly for each
Pascal value, uses nested loops, and prints the triangle in the expected shape.
The sample input 5 gives the correct Pascal Triangle values.

To improve it, check whether scanf successfully reads one integer and validate
that n is positive before calling pascalTriangle. For bigger inputs, the recursive
pascal function repeats many calculations, so an iterative combination formula or
row-by-row calculation would be more efficient. Also consider printing a newline
or error message for invalid input instead of silently printing nothing.
*/
