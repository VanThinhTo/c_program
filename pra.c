#include <stdio.h>

/* 
Write a program that prints a monthly calendar. The program reads through the standard input
the number of days in the month and the day of the week at which the month begins (1=Sunday, 7=Saturday).
Execution example:
$./a.out
number of days in month : 31
starting day of the week : 3
sun   mon  tue  wed  thu  fri  sat
             1    2    3    4    5
   6    7    8    9   10   11   12
  13   14   15   16   17   18   19
  20   21   22   23   24   25   26
  27   28   29   31   31
$ 
*/



/*
Score: 8.5/10

What is good:
- The main calendar logic is correct.
- The program reads the number of days and the starting weekday.
- It prints the weekday header.
- It prints the correct number of leading spaces before day 1.
- It correctly starts a new line after Saturday.
- It works for the sample input: 31 days, starting day 3.

What can be improved:
- Check whether scanf successfully reads the input values.
- Validate that days is between 28 and 31.
- Validate that start is between 1 and 7.
- Print an error message for invalid input instead of continuing.
- Add a final newline after the calendar if the last printed day does not
  already end the row.
- The variable remain works, but the line-break condition can be simpler by
  using the weekday position directly.

Improved code:

#include <stdio.h>

int main(){
    int days;
    int start;

    printf("number of days in month : ");
    if (scanf("%d", &days) != 1){
        printf("Invalid input\n");
        return 1;
    }

    printf("starting day of the week : ");
    if (scanf("%d", &start) != 1){
        printf("Invalid input\n");
        return 1;
    }

    if (days < 28 || days > 31){
        printf("Invalid number of days\n");
        return 1;
    }

    if (start < 1 || start > 7){
        printf("Invalid starting day\n");
        return 1;
    }

    printf("  sun  mon  tue  wed  thu  fri  sat\n");

    for (int i = 1; i < start; i++){
        printf("     ");
    }

    int weekday = start;

    for (int day = 1; day <= days; day++){
        printf("%5d", day);

        if (weekday == 7){
            printf("\n");
            weekday = 1;
        }
        else{
            weekday++;
        }
    }

    if (weekday != 1){
        printf("\n");
    }

    return 0;
}
*/

void rotateArrAlternative(){
    int n;

    if (scanf("%d", &n)!=1 || n<=0){
        printf("Invalid input\n");
        return;
    }

    int arr[n];

    for (int i=0; i<n; i++){
        if (scanf("%d", &arr[i])!=1){
            printf("Invalid input\n");
            return;
        }
    }

    int pos;
    if (scanf("%d", &pos)!=1 || pos<0 || pos>=n){
        printf("Invalid position\n");
        return;
    }

    for (int i=0; i<n; i++){
        printf("%d ", arr[(pos+i)%n]);
    }
    printf("\n");
}

int main(){
    rotateArrAlternative();
    return 0;
}

