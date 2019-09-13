#include <stdio.h>

int main (int argc, char ** argv) {
    int a;
    printf("Give an integer: ");
    scanf("%d", &a);
    if(a != 0)
    {
        printf("The number you entered does not equal zero \n");
    }
    else {
        printf("The number you entered equals zero \n");
    }

    float f1, f2;
    printf("Give two floats: ");
    scanf("%f %f", &f1, &f2);
    if(f1 >= f2)
    {
        printf("%f is the largest \n", f1);
    }
    else {
        printf("%f is the largest \n", f2);
    }

    int b;
    printf("Give an integer: ");
    scanf("%d", &b);
    if(b % 2 == 0)
    {
        printf("Result is: %d \n", b/2);
    }
    else {
        printf("Result is: %d \n", b*3);
    }   

    int e1, e2, e3;
    printf("Give three integers: ");
    scanf("%d %d %d", &e1, &e2, &e3);
    if((e1 == e2) || (e2 == e3) || (e1 == e3)    )
    {
        printf("Some numbers are equal \n");
    }
    else {
        printf("All are unique \n");
    }     

    
    return 0;
}