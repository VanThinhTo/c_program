#include <stdio.h>

#define MAX_SIZE 100

/*
============================================================
QUESTION 5. MERGE TWO SORTED ARRAYS AND SEARCH
Points: 3

Write a program that reads two sorted integer arrays and merges them into
one sorted array.

After merging, read one target value and search for it.

Requirements:
- Create a function merge that receives two sorted arrays and fills a third
  sorted array.
- Create a recursive binary search function that returns the index of the
  target in the merged array, or -1 if it is not found.
- The merged array may contain duplicates.
- Print the merged array before searching.

Input:
n
n sorted integers
m
m sorted integers
target

Example input:
4
1 3 3 9
5
0 2 3 7 10
7

Example output:
0 1 2 3 3 3 7 9 10
Found at index 6
============================================================
*/

void merge(int a[], int n, int b[], int m, int result[]) {
    int i=0;
    int j=0;
    int k=0;

    while (i<n && j<m){
      if (a[i]<b[j]){
        result[k] = a[i];
        k++;
        i++;
      }
      else if (a[i]>b[j])
      {
        result[k] = b[j];
        k++;
        j++;
      }
      else{
        result[k]=a[i];
        result[k+1]=b[j];
        k+=2;
        i++;
        j++;
      }
    }

    while (i<n){
      result[k]=a[i];
      k++;
      i++;
    }

    while (j<m){
      result[k]=b[j];
      k++;
      j++;
    }
}

int binary_search(int arr[], int left, int right, int target) {
  //base case
  if (left==right){
    if (target==arr[left]){
      return left;
    }
    else
      return -1;
  }  
  

  int mid=(right+left)/2;
  if (target==arr[mid]){
    return mid;
  }
  else if (target>arr[mid]){
    return binary_search(arr, mid+1, right, target);
  }
  else
    return binary_search(arr, left, mid-1, target);
  
  return -1;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i=0; i<n; i++){
      scanf("%d", &a[i]);
    }

    int m;
    scanf("%d", &m);

    int b[m];
    for (int i=0; i<m; i++){
      scanf("%d", &b[i]);
    }

    int result[n+m];
    merge(a, n, b, m, result);

    int target;
    scanf("%d", &target);

    for (int i=0; i<n+m; i++){
      printf("%d ", result[i]);
    }
    
    printf("\n");
    int index=binary_search(result, 0, n+m-1, target);
    if (index!=-1){
      printf("Found %d at index %d", target, index);
    }
    else
      printf("Not found");
    return 0;
}
