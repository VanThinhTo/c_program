/*
Improved version based on the current exercise_01_combination.c

Main improvements:
- main returns 0 for success and 1 for errors.
- n is checked explicitly, not only through r <= n.
- final output ends with a newline.
- factorial does not print errors; validation is handled in main.
*/

#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;
    }

    return n * factorial(n - 1);
}

unsigned long long combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main(void) {
    int n, r;

    if (scanf("%d %d", &n, &r) != 2) {
        printf("Invalid input\n");
        return 1;
    }

    if (n < 0 || r < 0 || r > n) {
        printf("ValueError: require 0 <= r <= n\n");
        return 1;
    }

    printf("C(%d, %d) = %llu\n", n, r, combination(n, r));
    return 0;
}
