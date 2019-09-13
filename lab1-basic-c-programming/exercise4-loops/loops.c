#include <stdio.h>

int main (int argc, char ** argv) {
    int i = 0;
    int j = 40;

    printf("Even numbers between %d and %d: \n", i, j);
    while(i < j+1){
        printf("%d ", i);
        i = i + 2;
    }

    int m, n;
    printf("\nNumbers 1 to 100: \n");
    for(m = 0; m < 10; m++){
        for(n = 1; n < 11; n++){
            printf("%2d ", m * 10 + n);
        }
        printf("\n");

    }

    int tf = 1;
    while(tf){
        int number;
        printf("Give a number: ");
        scanf("%d", &number);
        if (number != 0){
        printf("The square of %d is %d \n", number, (number*number));
        }
        else{
            tf = 0;
        }
    }
    printf("You entered zero. \n");
    
    return 0;
}