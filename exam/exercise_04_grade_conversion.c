/*
============================================================
EXERCISE 4. DISPLAY FUNCTION AND GRADE CONVERSION
============================================================

Question:
Write a complete C program that reads one student, converts the numeric
grade to a letter grade, and displays the result using functions.

Requirements:
- Define a Student structure with:
  - a name
  - a numeric grade
- Create a function that converts a numeric grade to a letter grade.
- Create a function that displays:
  - the student's name
  - the numeric grade
  - the converted letter grade
- Call the display function from main.
- Use this conversion table:
  - 30: A
  - 27-29: B
  - 24-26: C
  - 21-23: D
  - 18-20: E
  - 0-17: F
  - anything else: X

Example input:
Marco 28

Example output:
Name: Marco
Numeric grade: 28
Letter grade: B
*/
#include <stdio.h>

typedef struct
{
  char name[200];
  int grade;
  char let_grade;
} Student;

char convertGrade(int grade){
  if (grade==30){
    return 'A';
  }
  else if ((27<=grade) && (grade<=29)){
    return 'B';
  }
  else if ((24<=grade) && (grade<=26)){
    return 'C';
  }
  else if ((21<=grade) && (grade<=23)){
    return 'D';
  }
  else if ((18<=grade) && (grade<=20)){
    return 'E';
  }
  else
    return 'F';
}

Student InputStu(){
  char line[200];
  fgets(line, sizeof(line), stdin);

  Student s;

  sscanf(line, "%[^0123456789] %d", s.name, &s.grade);

  s.let_grade = convertGrade(s.grade);
  return s;
}

int main(){
  Student s = InputStu();
  printf("Name: %s\n", s.name);
  printf("Numeric grade: %d\n", s.grade);
  printf("Letter grade: %c\n", s.let_grade);
  return 0;
}

