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

int main(){
  int days;
  printf("number of days in month : ");
  scanf("%d", &days);

  int start;
  printf("starting day of the week : ");
  scanf("%d", &start);

  printf("  sun  mon  tue  wed  thu  fri  sat\n");
  
  int remain=7-start+1;

  for (int i=1; i<start; i++){
    printf("     ");
  }

  for (int day=1; day<days+1; day++){
    printf("%5d", day);

    if ((day+start-1)%7 ==0)
      printf("\n");
  }
}

