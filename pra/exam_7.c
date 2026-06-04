#include <stdio.h>

/*
============================================================
QUESTION 7. DATE VALIDATION, ORDINAL DAY, AND NEXT DATE
Points: 3

Write a program that reads a date as day month year.

Requirements:
- Create int is_leap(int year).
- Create int days_per_month(int month, int year).
- Create int valid_date(int day, int month, int year).
- Create int ordinal(int day, int month, int year), which returns the day
  number inside the year.
- Create void next_date(int *day, int *month, int *year), which modifies the
  date through pointers.
- If the date is invalid, print "Invalid date".
- Otherwise, print the ordinal day and the next date.

Example input:
28 2 2024

Example output:
Ordinal: 59
Next date: 29/2/2024

Example input:
31 11 2025

Example output:
Invalid date
============================================================
*/

int is_leap(int year) {
    if ((year%4==0 && year%100!=0) || (year%400==0)){
        return 1;
    }
    return 0;
}

int days_per_month(int month, int year) {
    /* TODO: implement this function. */
    return 0;
}

int valid_date(int day, int month, int year) {
    /* TODO: implement this function. */
    return 0;
}

int ordinal(int day, int month, int year) {
    /* TODO: implement this function. */
    return 0;
}

void next_date(int *day, int *month, int *year) {
    /* TODO: implement this function. */
}

int main(void) {
    /* TODO: implement Question 7 here. */
    return 0;
}
