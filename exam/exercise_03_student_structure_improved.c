#include <stdio.h>

/*
Improved version of exercise_03_student_structure.c

This version supports a name with more than one word in one input line.

Example input:
Alice Johnson 27

Example output:
Student name: Alice Johnson
Grade: 27
*/

typedef struct
{
  char name[200];
  int grade;
} Student;

Student InputStu(){
  Student s;
  char line[220];

  if (fgets(line, sizeof(line), stdin)==NULL){
    s.name[0]='\0';
    s.grade=0;
    return s;
  }

  if (sscanf(line, "%199[^\n0123456789] %d", s.name, &s.grade)!=2){
    s.name[0]='\0';
    s.grade=0;
  }

  return s;
}

int main(){
  Student s = InputStu();
  printf("Student name: %s\n", s.name);
  printf("Grade: %d\n", s.grade);

  return 0;
}
