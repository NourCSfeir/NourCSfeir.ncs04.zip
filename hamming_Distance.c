#include <stdio.h>
int hammingDistance(int x, int y);
int main(){   
    int x, y;
    while("true"){
        printf("Enter a pair of integers: ");
        scanf("%d %d", &x, &y);
        //we check the condition for if x or y is negative we reject the values.
        if(x < 0 || y < 0)
            break;
        else 
            printf("%d\n", hammingDistance(x, y));
    }
    return 0;
}
int hammingDistance(int x, int y){
//hD is a variable of type integer that stores the result of bitwise x XOR y
    int hD = x ^ y;
    //the variable setBits of type integer counts how many bits are set in the result of hD that indicate the difference between binary x and y
    int setBits = 0;
    //in the while loop, as long as hD is not negative, we use bitwise AND with the result of hD to increment the setBits, indicating we have a 1. Then, we shift the hD one unit to the right.
    while (hD > 0) {
        if((hD & 1) == 1)
            setBits++;
        hD = hD >> 1;
    }
    setBits return the number of position by which the values x and y differ
    return setBits;
}
