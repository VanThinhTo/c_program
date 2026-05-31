/*
============================================================
EXERCISE 3. SIMPLE STUDENT STRUCTURE
============================================================

Question:
Write a complete C program that stores one student's data using a structure.

Requirements:
- Define a structure named Student.
- The structure must contain:
  - a name
  - a numeric grade
- Read one student's name and grade from standard input.
- Store the values inside a Student variable.
- Print the student's name and grade.

Example input:
Alice 27

Example output:
Student name: Alice
Grade: 27
*/

#include <stdio.h>

typedef struct
{
  char name[200];
  int grade;
} Student;

Student InputStu(){
  char input[220];
  fgets(input, sizeof(input), stdin);

  Student s;
  sscanf(input, "%[^0123456789] %d", s.name, &s.grade);

  return s;
}

int main(){
  Student s = InputStu();
  printf("Student name: %s\n", s.name);
  printf("Grade: %d", s.grade);

  return 0;
}
