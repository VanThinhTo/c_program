#include <stdio.h>

#define MAX_SIZE 100

/*
============================================================
QUESTION 6. POINTERS, ARRAY REVERSAL, AND MATRIX SUM
Points: 3

Write a program that practices pointers with arrays and matrices.

The program reads:
1. an array size n
2. n integers
3. matrix dimensions rows and cols
4. rows * cols integers

Requirements:
- Create a function void swap(int *a, int *b).
- Create a function void reverse_pointer(int *arr, int size) that reverses
  the array using pointer arithmetic.
- Create a function int sum_matrix(int rows, int cols, int m[rows][cols]).
- Print the reversed array.
- Print the matrix sum.

Example input:
5
1 2 3 4 5
2 3
1 2 3
4 5 6

Example output:
5 4 3 2 1
Matrix sum: 21
============================================================
*/

void swap(int *a, int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

void reverse_pointer(int *arr, int size) {
    for (int i=0; i<size/2; i++){
        swap(&arr[i], &arr[size-1-i]);
    }
}

int sum_matrix(int rows, int cols, int m[rows][cols]) {
    int sum=0;
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            sum+=m[i][j];
        }
    }
    return sum;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int rows, cols;
    scanf("%d", &rows);
    scanf("%d", &cols);

    int m[rows][cols];

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            scanf("%d", &m[i][j]);
        }
    }

    reverse_pointer(arr, n);
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    int sum = sum_matrix(rows, cols, m);
    printf("Matrix sum: %d", sum);

    return 0;
}
