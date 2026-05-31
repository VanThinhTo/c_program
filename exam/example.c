#include <stdio.h>
/*
C PROGRAMMING EXAM – SET C

Duration: 90 minutes
Total: 10 points

Instructions:
Write complete C programs for each question.
Your programs must compile without errors and use only standard C libraries.
*/


/*
============================================================
QUESTION 1. BASIC ARRAY PROCESSING
Points: 2

Write a C program that reads an integer array and finds:
1. The maximum value in the array
2. The minimum value in the array
3. The average value of all elements

Requirements:
- Read the number of elements n.
- Read n integers into an array.
- Print the maximum value, minimum value, and average value.
- The average should be printed with two decimal places.

Input:
The first line contains an integer n.
The second line contains n integers.

Output:
Print the maximum value, minimum value, and average value.

Example input:
5
1 3 5 7 9

Example output:
Maximum: 9
Minimum: 1
Average: 5.00
============================================================
*/
void desArr(){
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int min=arr[0];
    int max=arr[0];
    double sum=0.00;

    for (int i=0;i<n;i++){
        if (arr[i]<min){
            min=arr[i];
        }
        if (arr[i]>max){
            max=arr[i];
        }
        sum+=arr[i];
    }

    double avg=sum/n;

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Average: %.2f\n", avg);
}



/*
============================================================
QUESTION 2. PASCAL'S TRIANGLE USING RECURSION
Points: 2.5

Write a C program that prints Pascal's Triangle using recursion.

The value at row n and column k in Pascal's Triangle is defined as:

C(n, k) = 1, if k == 0 or k == n
C(n, k) = C(n - 1, k - 1) + C(n - 1, k), otherwise

Requirements:
- Use a recursive function to calculate each value in Pascal's Triangle.
- Read the number of rows from the user.
- Print Pascal's Triangle with the given number of rows.

Input:
The input contains one integer n, the number of rows.

Output:
Print Pascal's Triangle with n rows.

Example input:
5

Example output:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
============================================================
*/
int pascal(int row, int col){
    //base case
    if ((col==0) || (row==col)){
        return 1;
    }

    //recursive C(n, k) = C(n - 1, k - 1) + C(n - 1, k)
    return (pascal(row-1, col) + pascal(row-1, col-1));
}

void pascalTriangle(){
    int row;
    scanf("%d", &row);

    for (int i=0; i<row; i++){
        for (int j=0; j<=i; j++){
            printf("%d ", pascal(i, j));
        }
        printf("\n");
    }
}

/*
============================================================
QUESTION 3. ROTATE AN ARRAY FROM A GIVEN POSITION
Points: 2.5

Write a C program that rotates an array from a given position.

For example, if the array is:

1 3 5 7 9

and the selected position is 2, the output should be:

5 7 9 1 3

Assume that the position is counted from 0.

Requirements:
- Read the size of the array n.
- Read n integers into the array.
- Read an integer pos, representing the position where rotation starts.
- Print the rotated array.
- The elements from pos to the end of the array should appear first.
- The elements before pos should appear after them.

Input:
The first line contains an integer n.
The second line contains n integers.
The third line contains an integer pos.

Output:
Print the rotated array.

Example input:
5
1 3 5 7 9
2

Example output:
5 7 9 1 3

Another example input:
6
10 20 30 40 50 60
3

Another example output:
40 50 60 10 20 30
============================================================
*/
void rotateArr(){
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    int pos;
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        return;
    }

    int tempArr[n];
    int i=0;

    for (int p=pos;pos<n;pos++){
        tempArr[i]=arr[p];
        i++;
    }

    int j=0;

    while (i<n){
        tempArr[i]=arr[j];
        i++;
        j++;
    }

    for (int i=0; i<n; i++){
        printf("%d ", tempArr[i]);
    }
}

/*
============================================================
QUESTION 4. COUNT CONSONANTS IN A PARAGRAPH
Points: 3

Write a C program that reads a paragraph, including multiple lines,
and counts the total number of consonants in the paragraph.

A consonant is an English alphabet letter that is not a vowel.

The vowels are:
a, e, i, o, u
A, E, I, O, U

All other English alphabet letters are considered consonants.

Requirements:
- Read a paragraph that may contain spaces and newline characters.
- Count both uppercase and lowercase consonants.
- Ignore digits, spaces, punctuation marks, and special characters.
- Stop reading input when the end-of-file condition is reached.
- Print the total number of consonants.

Input:
The input contains a paragraph with one or more lines.

Output:
Print the number of consonants in the paragraph.

Example input:
Hello World
C Programming is fun!

Example output:
Consonants: 19

Explanation:
The consonants are counted from both lines.
Vowels, spaces, punctuation marks, and the exclamation mark are ignored.
============================================================
*/
int is_vowel(char c){
    char vowels[11]="aeiouAEIOU";

    for (int i=0; vowels[i]!='\0'; i++){
        if (c==vowels[i])
            return 1;
    }
    return 0;
}

int is_letter(char c){
    if ((c>='a' && c<='z') || (c>='A' && c<='Z')){
        return 1;
    }
    return 0;
}

int consonants(){
    int c;
    int count=0;

    while ((c=getchar())!=EOF){
        if (is_letter(c) && !is_vowel(c)){
            count++;
        }
    }
    return count;
}


int main(){
    // desArr();
    // pascalTriangle();
    // rotateArr();
    int count = consonants();
    printf("%d", count);
    return 0;
}