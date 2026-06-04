#include <stdio.h>

#define MAX_STUDENTS 100
#define MAX_NAME 80

typedef struct {
    char name[MAX_NAME];
    int grade;
    char letter;
} Student;

/*
============================================================
QUESTION 4. STUDENT GRADES, AVERAGE, AND MODE
Points: 3

Write a program that reads n students and their numeric grades.

Each student has:
- a name
- a numeric grade from 18 to 30
- a letter grade

Use this conversion table:
- 30: A
- 27-29: B
- 24-26: C
- 21-23: D
- 18-20: E
- anything else: X

Requirements:
- Define a Student structure.
- Create a function char convert_grade(int grade).
- Read n students.
- Print each student with numeric and letter grade.
- Print the average grade with two decimal places.
- Print the mode grade. If more grades have the same maximum frequency,
  print all of them.

Example input:
5
Marco 28
Anna 30
Luca 28
Sara 24
Paolo 30

Example output:
Marco 28 B
Anna 30 A
Luca 28 B
Sara 24 C
Paolo 30 A
Average: 28.00
Mode: 28 30
============================================================
*/

char convert_grade(int grade) {
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
    else if ((18<=grade) && (grade<=20))
        return 'E';

    return 'X';
}

int main(void) {
    int n;
    scanf("%d", &n);

    Student students[n];
    int freq[13]={0};
    double sum=0.0;

    for (int i=0; i<n; i++){ 
        if (scanf("%79s %d", students[i].name, &students[i].grade)==2){
            students[i].letter = convert_grade(students[i].grade);
            sum+=students[i].grade;
            freq[students[i].grade-18]++;
        }
    }

    for (int i=0; i<n; i++){
        printf("%s %d %c\n", students[i].name, students[i].grade, students[i].letter);
    }

    printf("Average: %.2f\n", sum/n);

    int mode=0;
    for (int i=0; i<13; i++){
        if (freq[i]>mode){
            mode=freq[i];
        }
    }

    printf("Mode: ");
    for (int i=0; i<13; i++){
        if (freq[i]==mode){
            printf("%d ", i+18);
        }
    }

    return 0;
}
