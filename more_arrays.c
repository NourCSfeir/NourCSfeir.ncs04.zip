#include <stdio.h>
#include <string.h>
#define r 2
#define c 3
void concat(char *array[r][c]);
/*
Specification
this method merges 2D array of strings as input. Then, it returns a 1D array containing the concatenation of elements in each element of the 2D array.
Test cases:
Many 2d array strings should work. But the commented section prints every element in the array. However, the second part of the code attempts to solve the issue of printing the 6 elements from the given example to 2 elements, but it doesnt show any result with the use of strcat from string library.
*/
int main(){
char *array[r][c] = {{"I", "LOVE", "CODING"}, {"THIS", "IS", "SPARTA"}};
concat(array);
}
// void concat(char *array[r][c]){
// int i, j, k = 0;
// char *result[r];
// while(array[i][j] != NULL){
//     result[k] = array[i][j];
//     j++;
//     k++;
// }
// i++;
// j = 0;
// while(array[i][j] != NULL){
//     result[k] = array[i][j];
//     j++;
//     k++;
// }
// for(int i = 0; i < 6; i++)
//     printf("%s \n", result[i]);
// }

void concat(char *array[r][c]){
int i, j, k = 0;
char *result[r];
//merging each element from 2d array to 1d array
while(array[i][j] != NULL){
    strcat(result[k],array[i][j]);
    j++;
    k++;
}
i++;
j = 0;
while(array[i][j] != NULL){
    strcat(result[k],array[i][j]);
    j++;
}
//printing the 2 elements in result
for(int i = 0; i < 2; i++)
    printf("%s \n", result[i]);

}
