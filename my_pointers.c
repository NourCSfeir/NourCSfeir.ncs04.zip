#include <stdio.h>
void merge1(char *a1, int m, char *b1, int n, char *c1){
int i=0,j=0,k=0;
  //Merging the two arrays
  while(i < m && j < n){
    if(a1[i] < b1[j]){
      c1[k] = a1[i]; 
      i++;
    }
    else{
      c1[k] = b1[j]; 
      j++;
    }
    k++;
  }
  //Elements left in first array
  if(i < m)
    while(i < m){
      c1[k] = a1[i]; 
      i++; 
      k++;
    }
  //Elements left in second array
  else
    while(j < n){
      c1[k] = b1[j]; 
      j++; 
      k++;
    }
  //Printing the characters in the resulting c1 array
    for(int i = 0; i < m+n; i++){
        printf("%c ", c1[i]);
    }
}
int main(){
char *a1[] = {"ab", "ac"};
int sizeA1 = sizeof(a1) / sizeof(a1[0]);
char *b1[] = {"za", "zb", "zzzzc"};
int sizeB1 = sizeof(b1) / sizeof(b1[0]);
char *c1[sizeA1 + sizeB1];
 for(int i =0 ; i < sizeA1; i++)
     printf("%s\n", a1[i]);
 for(int j = 0; j < sizeB1; j++)
     printf("%s\n", b1[j]);
merge1(*a1, sizeA1*3, *b1, sizeB1*4, *c1);
}
