// C program to read input until EOF using scanf()
#include <stdio.h>
// #include <string.h>

int inputeof(void){
    // Variable to store each number read
    int num;
    // Counter for number of integers read
    int count = 0;

    printf("Enter your inputs or (Press Ctrl+D on Unix and MacOS or "
           "Ctrl+Z on Windows for EOF):\n");

    // Read integers until EOF is encountered
    while (scanf("%d", &num) == 1) {
        count++;
        // Print each number with its count
        printf("You entered: Number %d: %d\n", count, num);
    }

    printf("\nEOF reached. Total numbers read: %d\n",
           count);

    return 0;
}