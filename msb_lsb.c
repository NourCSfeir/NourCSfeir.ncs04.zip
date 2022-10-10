#include <stdio.h>
#include <math.h>

int msb(int x);
int lsb(int y);
int main(){
    int num;
    printf("Enter a positive non-zero integer: ");
    scanf("%d", &num);
  //the result that outputs the distance between the first and last bits set to 1 in the main is calculated by subtracting the results of lsb from msb. Then, the result is printed.
    int result = msb(num) - lsb(num);
    //printf("%d\n", msb(num));
    //printf("%d\n", lsb(num));
    printf("Result: %d", result);
    return 0;
}
/*msb function: takes as input a positive non-zero integer in parameter. msb integer variable is created 
and assigned to it a formula to determine the msb value of the non-binary value in the input to the binary number. 
Then, the result, that indicates the position of the most significant bit that is set to 1, is printed and returned.*/

int msb(int x){
int msb = floor(log2(x));
printf("%d\n", msb);
return msb;
}
/*lsb function: takes as input a positive non-zero integer in parameter. lsb integer variable is created 
and assigned to it a formula to determine the lsb value of the non-binary value in the input to the binary number. 
Then, the result, that indicates the position of the least significant bit that is set to 1, is printed and returned.*/

int lsb(int y){
int lsb = log2(y & -y);
printf("%d\n", lsb);
return lsb;
}
