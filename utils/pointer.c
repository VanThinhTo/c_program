#include<stdio.h>


// define a function that swaps two variables
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//write a function that takes an array of int and
//puts in in reverse order

void reverse(int arr[], int size){  
    for (int i=0; i<size/2; i++){
        swap(&arr[i], &arr[size-1-i]);
    }
}

//translate this function using pointer
void reverse_pointer(int *arr, int size){  
    for (int i=0; i<size/2; i++){
        swap((arr+i), (arr+size-1-i));
    }
}

//print a 2D array
void printMatrix(int rows, int cols, int (*m)[cols]){
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            printf("%d ", *(*(m+i)+j));
        }
        printf("\n");
    }
}

//sum a 2D array
int sumMatrix(int rows, int cols, int (*m)[cols]){
    int sum = 0;
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            sum += *(*(m+i)+j);
        }
    }
    return sum;
}

//Access elements using flatten memory
void printMatrixFlatten(int rows, int cols, int (*m)[cols]){
    int *p=&m[0][0];
    //we can do this because the memories are continuous
    for (int i=0;i<rows*cols;i++){
        printf("%d ", *(p+i));
    }
}

//Modify values of the matrix
void modifyMatrix(int rows, int cols, int (*m)[cols], int row, int column, int value){
    for (int i=0;i<rows;i++){
        for (int j=0;j<3;j++){
            if ((i==row-1) && (j==column-1)){
                *(*(m+row-1)+column-1) = value;
            }
        }
    }
}

//minimum between numbers
int * minimum(int *a,int *b){
    if (*a<*b)
    {
        return a;
    }
    else if (*a>*b)
    {
        return b;
    }
    else
    {
        return NULL;
    }
}

// fraction's normal form

int gcd_iterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void normalize(int *n, int *d){
    printf("%d/%d = ", *n, *d);
    int gcd = gcd_iterative(*n, *d);
    while (gcd != 1){
        *n = *n/gcd;
        *d = *d/gcd;
        gcd = gcd_iterative(*n, *d);
    }
    printf("%d/%d \n", *n, *d);
}

//the next date
void nextDate(unsigned *month, unsigned *date, unsigned *year){
    if (!validDate(*month, *date, *year)){
        printf("The input date (%u/%u/%u) is not valid\n", *month, *date, *year);
        return;
    }

    unsigned daysInmonth = daysPerMonth(*month, *year);

    if (*date<daysInmonth){
        (*date)++;
    }
    else{
        (*date) = 1;

        if (*month<12){
            (*month)++;
        }
        else{
            (*year)++;
            *month=1;
        } 
    }
    printf("The next date is %u/%u/%u\n", *month, *date, *year);
}