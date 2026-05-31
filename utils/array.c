#include<stdio.h>

int array(void){
    char name[7]="Hello";
    for (int i=0; i<10; i++){
        printf("%c ", name[i]);
    }
    return 0;
}

//Print an array with n elements
void printElement(int a[], int size){
    for (int i=0; i<size; i++){
        printf("%d ", a[i]);
    }
}

//Compute the average of elements
double avgArr(int a[], int size){
    float sum = 0;
    for (int i=0; i<size; i++){
        sum+=a[size];
    }
    return (sum/size);
}

//Reverse an array
//See pointer file

//Find the minimum value
int minArr(int a[], int size){
    int min = a[0];
    for (int i=1; i<size; i++){
        if (a[size]<min){
            min = a[size];
        }
    }
    return min;
}

//Work with a 2D matrix (sum all elements)
void printArr2D(int row, int col, int a[row][col]){
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

/*
grades [18, 30] input, find mode

int grades[max] = {0}; int grade
while (scanf("%d", &grade) == 1 and 18<=grade=<30)
grades[grade-18]++;
*/
// typedef struct{
//     int mode;
//     int grade;
// } ModeGrade;

void mode_grade(){
    int grades[13]={0};
    int grade;
    int valid_input;

    while (scanf("%d", &grade)==1 && (18<=grade) && (grade<=30)){
        grades[grade-18]++;
        valid_input++;
    }

    if (valid_input==0){
        printf("No valid input");
        return;
    }

    int mode=grades[0];

    for (int i=1; i<13; i++){
        if (grades[i]>=mode){
            mode=grades[i];
        }
    }

    for (int i=0; i<13; i++){
        if (grades[i]==mode){
            printf("Value: %d Mode: %d\n", i+18, mode);
        }
    }
}


/*
sort values in ascending order or descending order from scratch
2 solutions:
- compare => swap
- mergesort
+ mergesort: recursive
+ merge: not recursive
*/
//Method 1: swap util finish
void sortArr(int arr[], int size){
    if (size==1){
        return;
    }

    for (int i=0; i<size-1;i++){
        int temp;
        if (arr[i]>arr[i+1]){
            temp=arr[i+1];
            arr[i+1]=arr[i];
            arr[i]=temp;
        }
    }

    sortArr(arr, size-1);
}

//Method2: mergesort
//see mergesort.c file

/*
given a sorted array, 
if the index of value, we can do like the guessing number in python, find the middle => compare,
then find the middle again
*/
void guessing(int arr[], int size){
    int left=0, right=size-1, guess=0;
    
    while (!guess){
        int mid=(right+left)/2;
        int guess_num = arr[mid];

        printf("The number is %d\n", guess_num);
        printf("Is your number <,>,or=?\n");
        
        char guide;
        scanf(" %c", &guide);
        
        if (guide=='='){
            guess=1;
        }
        else if (guide=='<')
        {
            right=mid-1;
        }
        else{
            left=mid+1;
        }
        
    }
}

//merge
void merge(int a[], int size_a, int b[], int size_b, int c[]){
    int i=0, j=0, k=0;
    
    while (i<size_a && j<size_b){
        if (a[i]<=b[j]){
            c[k] = a[i];
            i++;
        }
        else if (a[i]>b[j])
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    while (i<size_a){
        c[k]=a[i];
        i++;
        k++;
    }

    while (j<size_b){
        c[k]=b[j];
        j++;
        k++;
    }
}

//mergesort
void mergeSort(int arr[], int size){
    // Base case
    if (size <= 1) {
        return;
    }

    // Divide the array into two sub-arrays
    int mid = size / 2;

    // Create leftArr and rightArr
    int leftSize=mid;
    int rightSize=size-mid;

    int leftArr[leftSize];
    int rightArr[rightSize];

    // Copy data from arr to leffArr and rightArr
    for (int i=0;i<leftSize;i++){
        leftArr[i]=arr[i];
    }

    for (int i=0;i<rightSize;i++){
        rightArr[i]=arr[mid+i];
    }

    // Sort leftArr
    mergeSort(leftArr, leftSize);

    // Sort rightArr
    mergeSort(rightArr, rightSize);

    // Merge two sub-arrays
    merge(leftArr, leftSize, rightArr, rightSize, arr);
}

//readline
int readLine(char line[], int max){
    int c;
    int i=0;

    while (i<max-1 && (c=getchar())!=EOF && c!='\n'){
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}

//palyndrome
_Bool palyndrome(char *s){
    int len=0;

    while (s[len]!='\0'){
        len++;
    }

    for (int i=0;i<len/2;i++){
        if (s[i]!=s[len-i-1]){
            return 0;
        };
    }

    return 1;
}

int is_digit(char c){
    if (c>='0' && c<='9'){
        return 1;
    }
    return 0;
}

//integer extraction
int extractInt(char *s){
    int len=0;

    while (s[len]!='\0'){
        len++;
    }

    char digit[100];
    int j=0, flag=0;

    for (int i=0; i<len; i++){
        if (is_digit(s[i])){
            digit[j] = s[i];
            j++;
            flag=1;
        }
    }

    digit[j]='\0';

    if (flag==0)
        return -1;
    
    int n;
    sscanf(digit, "%d", &n);
    return n;
}

//strcmp
int myStrcmp(char *s1, char *s2){
    int i=0;

    while (s1[i]!='\0' && s2[i]!='\0'){
        if (s1[i]<s2[i]){
            return -1;
        }
        else if (s1[i]>s2[i]){
            return 1;
        }
        i++;
    }

    //s1 is longer than s2
    if (s1[i]=='\0' && s2[i]!='\0'){
        return -1;
    }

    //s2 is longer than s1
    else if (s1[i]!='\0' && s2[i]=='\0'){
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

//countwords
int countwords(char s[]){
    int i=0;
    int count=0;
    int inword=0;

    while (s[i]!='\0'){
        if (is_letter(s[i])){
            if (inword==0){
                count++;
                inword=1;
            }
        }
        else{
            inword=0;
        }
        i++;
    }

    return count;
}

//first occurrence
char *firstOccurrence(char *s1, char *s2){
    if (s2[0]=='\0'){
        return s1;
    }

    for (int i=0; s1[i]!='\0'; i++){
        int j=0;
        while (s2[j]==s1[i+j]){
            j++;
        }

        if (s2[j]=='\0'){
            return s1+i;
        }
    }

    return NULL;
}

//replaceall
int replaceall(char *s1, char a, char b){
    int count=0;

    for (int i=0; s1[i]!='\0'; i++){
        if (s1[i]==a){
            s1[i]=b;
            count++;
        }
    }
    
    return count;
}

//base conversion
//base case: n<b or n/b=0
//recursive: baseCon(n/b, b)
void baseCon(int n, int b){
    char symbol[] = {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
    };

    //base case
    if (n<b){
        printf("%c", symbol[n]);
    }
    //recursive
    else{
        baseCon(n/b, b);
        printf("%c", symbol[n%b]);
    }
}

void baseConvert(int n, int b){
    char symbol[] = {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
    };

    char result[32];
    int i=0;

    if (b<2 || b>16){
        printf("Invalid base\n");
        return;
    }

    if (n==0){
        printf("0");
        return;
    }

    while (n>0){
        result[i]=symbol[n%b];
        n=n/b;
        i++;
    }

    for (int j=i-1; j>=0; j--){
        printf("%c", result[j]);
    }
}

//anagrams
void freq_letter(char *s, int freq_alpha[]){
    for (int i=0; s[i]!='\0'; i++){
        if (is_letter(s[i])){
            freq_alpha[s[i]-'a']++;
        }
    }
}

int anagrams(){
    char s1[100];
    char s2[100];
    char c;
    int i=0, j=0;

    while ((c=getchar())!=EOF && is_letter(c)){
        s1[i]=c;
        i++;
    }
    s1[i] = '\0'; 

    while ((c=getchar())!=EOF && is_letter(c)){
        s2[j]=c;
        j++;
    }
    s2[j] = '\0'; 


    int freq_s1[26]={0};
    int freq_s2[26]={0};

    freq_letter(s1, freq_s1);
    freq_letter(s2, freq_s2);

    for (int i=0; i<26; i++){
        if (freq_s1[i]!=freq_s2[i])
            return 0;
    }

    return 1;
}