#include <stdio.h>
#define SIZE 10
//Symbolic constant called SIZE with value 10, to be used to refer to the size of the array when needed.
//the return type and name of the functions and their parameters are declared before the main.
void printArray(int a[]);
void arrayHistogram(int a[]);
void swapValues(int a[], int i, int j);
void bubbleSort(int a[]);
int median(int a[]);
int mode(int a[]);
int isSorted(int a[], int size);

int main(){
    int array[SIZE] = {1, 1, 1, 1, 1, 2, 2, 2, 3, 3};
    int a[SIZE] = {5, 3, 6, 8, 15, 0, 4, 9, 23, 14};
    bubbleSort(a);
    printArray(array);
    arrayHistogram(array);
    printf("\n\n");
    swapValues(array, 3, 6);
    printf("\n"); 
    printf("%d ", median(a));
    printf("\n");
    printf("%d ", mode(array));
    printf("\n");
    printf("%d", isSorted(a, SIZE));
return 0;
}
//printArray function takes as a parameter an array with a defined size and uses a for loop to print all elements of the array under "Index" and "Value".
void printArray(int a[SIZE]){
   printf("%s %9s\n","Index","Value");
   for (size_t i = 0; i < SIZE; i++)
      printf("%5zu %9d\n", i, a[i]); //zu: z refers to size_t and u represents unsigned number;d represents an integer; 5 and 9 are for the space width. 
}
//swapValues function takes as parameters an array of defined size with two variables i and j to represent the positions to be swapped.
void swapValues(int a[SIZE], int i, int j){
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
    for(int k = 0; k < SIZE ; k++){
        printf("%d ", a[k]);
    }
    printf("\n");
}
/*the function bubbleSort takes an array of defined size as the parameter. Several passes will be performed through the array, meaning that every successive
pairs of elements are compared. If the pair are in decreasing order, they are passed on the function swapValues to return the increasing order of the pairs.*/
void bubbleSort(int a[SIZE]){
  for (int k = 0; k < SIZE -1; k++) {
    for (int i = 0; i < SIZE - k - 1; i++) {
      if (a[i] > a[i + 1]) {
        swapValues(a, i, i+1);
      }
    }
  }
  printf("\n");
}
//the median function calculates the median of an array passed on as the parameter and uses the function bubbleSort to sort your array before returning the median.
int median(int a[SIZE]){
    bubbleSort(a);
    int median = a[SIZE/2];
    return median;
}
//mode function that takes an array of defined size and returns the mode of an array.
int mode(int a[SIZE]){
    int max, maxCount = 0;
  //the variable count determines how many numbers are repeated the most
    for (int i = 0; i < SIZE; i++) {
        int count = 0;
        for (int j = 0; j < SIZE; j++) {
            if (a[j] == a[i])
            count++;
        }
      //the if statement compares count with maxCount and returns the maximum value in the array.
        if (count > maxCount) {
            maxCount = count;
            max = a[i];
      }
   }
   return max;
}
//the function isSorted takes as parameters an array and size. It then checks whether the elements in the array, by comparing them, are in increasing sorted order, 1, or not, 0.
int isSorted(int a[], int size){
    for(int i = 0; i < size - 1; i++){
        if(a[i] >  a[i + 1])
            return 0;
    }
    return 1;
}
//the function arrayHistogram takes an array of defined size in the parameter. It then stores in an array of size 3, how many times the three digits are repeated.
void arrayHistogram(int a[SIZE]){
    int count[3] = {0, 0, 0};
    for(int i = 0; i < SIZE; i++){
        if(a[i] == 1)
        count[0]++;
        else if(a[i] == 2)
        count[1]++;
        else if(a[i] == 3)
        count[2]++;
    }
  //the following the way to print the output. s represents strings "Value", "Frequency", and "Histogram".
  //the number of stars under histogram represent the frequency of each value.
    printf("%s %s %s","Value","Frequency","Histogram");
    for(int i = 0; i < 3; i++){
        printf("\n%5d%9d      ", i+1, count[i]);
        for(int j = 0; j < count[i]; j++){
             printf("*");
        }
    } 
}
