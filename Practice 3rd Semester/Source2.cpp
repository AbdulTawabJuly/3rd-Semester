#include <stdio.h>  

//isHappyNumber() will determine whether a number is happy or not  
int isHappyNumber(int num) {
    int rem = 0, sum = 0;

    //Calculates the sum of squares of digits  
    while (num > 0) {
        rem = num % 10;
        sum = sum + (rem * rem);
        num = num / 10;
    }
    return sum;
}

int main()
{
    //Displays all happy numbers between 1 and 100  
    printf("List of happy numbers between 1 and 100: \n");
    for (int i = 1000; i <= 9999; i++) {
        int result = i;

        //Happy number always ends with 1 and   
        //unhappy number ends in a cycle of repeating numbers which contains 4  
        while (result != 1 && result != 4) {
            result = isHappyNumber(result);
        }

        if (result == 1)
            printf("%d ", i);
    }

    return 0;
}