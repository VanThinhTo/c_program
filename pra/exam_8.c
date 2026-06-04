#include <stdio.h>

/*
============================================================
QUESTION 8. TEXT ANALYSIS UNTIL EOF
Points: 3

Write a program that reads text from standard input until EOF and prints:
1. the number of words
2. the number of vowels
3. the number of consonants
4. the length of the longest word

Requirements:
- A word is a sequence of English letters.
- Vowels are a, e, i, o, u and their uppercase versions.
- Ignore digits, spaces, punctuation marks, and special characters.
- Create helper functions:
  - int is_letter(char c)
  - int is_vowel(char c)
- Use getchar in a loop until EOF.

Example input:
Hello World
C Programming is fun!

Example output:
Words: 6
Vowels: 8
Consonants: 19
Longest word length: 11
============================================================
*/

int is_letter(char c) {
    return ((c>='a' && c<='z') || (c>='A' && c<='Z'));
}
// a, e, i, o, u
int is_vowel(char c) {
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
        return 1;
    }
    return 0;
}

int str_len(char s[]){
    int len=0;
    while (s[len]!='\0'){
        len++;
    }
    return len;
}

int main(void) {
    int count_word=0;
    int count_consonant=0;
    int count_vowel=0;
    int max_len=0;
    int c;
    int inword=0;
    int len_word=0;

    while ((c=getchar())!=EOF){
        if (is_letter(c)){
            //count vowels and consonants
            if (is_vowel(c)){
                count_vowel++;
            }
            else{
                count_consonant++;
            }

            //count words
            if (inword==0){
                count_word++;
                inword=1;
            }
        }
        else{
            inword=0;
        }

        if (inword==1){
            len_word++;
        }
        else{
            if (len_word>max_len){
                max_len=len_word;
            }
            len_word=0;
        }
    }
    
    printf("Words: %d\n", count_word);
    printf("Vowels: %d\n", count_vowel);
    printf("Consonants: %d\n", count_consonant);
    printf("Longest word length: %d\n", max_len);
    return 0;
}
