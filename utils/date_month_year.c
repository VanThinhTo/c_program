#include<stdio.h>

int change(int x){
    x = 10;
    return x;
} // remember that we can not modify x directly

// define these functions

/*
yy is leap if yy can be divided by 4 but not by 100
or yy can be divided by 400
*/

int isleap(int year){
    return (year%4==0 && year%100!=0 || year%400==0);
}

// return number of dates in a month, given month and year
int daysPerMonth(int month, int year){
    if (month<0 && month>12){
        return 0;
    }
    else if (month == 2){
        if (isleap(year)){
            return 29;
        }
        else
            return 28;
    }

    else if (month==4 || month ==6|| month==9|| month==11){
        return 30;
    }
    else
        return 31;
}

//check if the date is valid
int validDate(int day, int month, int year){
    if (daysPerMonth(month, year)==0 || day>daysPerMonth(month, year))
        return 0;
    else if (day<0 || year<0)
        return 0;
    else 
        return 1;
}

//convert a date to its ordinal. Ex: 01/02/2026 is the 32th date of that year
int ordinal(int day, int month, int year){
    if (!validDate(day, month, year)){
        return 0;
    }
    else{
        int ordinal=0;
        for (int i=1;i<month;i++){
            ordinal += daysPerMonth(i, year);
        }
        ordinal += day;
        return ordinal;
    }
    
}

