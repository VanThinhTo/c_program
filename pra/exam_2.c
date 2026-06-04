#include <stdio.h>

/*
============================================================
QUESTION 2. MONTHLY CALENDAR
Points: 2

Write a program that prints a monthly calendar.

The program reads:
1. the number of days in the month
2. the day of the week on which the month starts

Use this convention:
- 1 = Sunday
- 2 = Monday
- ...
- 7 = Saturday

Requirements:
- Validate that the number of days is between 28 and 31.
- Validate that the starting day is between 1 and 7.
- Print the weekday header.
- Use nested loops or carefully controlled loops to align the days.

Example input:
31
3

Example output:
sun  mon  tue  wed  thu  fri  sat
           1    2    3    4    5
  6    7    8    9   10   11   12
 13   14   15   16   17   18   19
 20   21   22   23   24   25   26
 27   28   29   30   31
============================================================
*/

int main(void){
    int days;
    printf("number of days in month : ");
    if ((scanf("%d", &days)!=1) || (days<28) || (days>31)){
        printf("Invalid input of days");
        return 1;
    }

    int start;
    printf("starting day of the week : ");
    if ((scanf("%d", &start)!=1) || (start<1) || (start>7)){
        printf("Invalid input of starting day");
        return 1;
    }

    printf("  sun  mon  tue  wed  thu  fri  sat\n");

    for (int i=0; i<(start-1)*5; i++){
        printf(" ");
    }

    int remain = 7-start+1;

    for (int day=1; day<=days; day++){
        printf("%5d", day);
        remain--;
        if (remain==0){
            printf("\n");
            remain=7;
        }
    }

    return 0;
}
