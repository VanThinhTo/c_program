#include <stdio.h>

/*
Pascal Triangle using row-by-row calculation.

This avoids recursive repeated calls. Each row starts with 1, then each next
value is calculated from the previous value in the same row.
*/

void pascalTriangle(int n) {
    for (int row = 0; row < n; row++) {
        unsigned long long value = 1;

        for (int space = 0; space < n - row - 1; space++) {
            printf("  ");
        }

        for (int col = 0; col <= row; col++) {
            printf("%llu   ", value);
            value = value * (row - col) / (col + 1);
        }

        printf("\n");
    }
}

int main(void) {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    if (n <= 0) {
        printf("Number of rows must be positive\n");
        return 1;
    }

    pascalTriangle(n);
    return 0;
}
