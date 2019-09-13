#include <stdio.h>

int main (int argc, char ** argv) {
    int a = 10, b = 3;
    float f1 = 1, f2 = 3;
    
    printf("One half is 50 %% \n");
    printf("The difference between %d and %d is %d \n", a, b, a-b);
    printf("%f / %f is %f \n", f1, f2, f1/f2);

    return 0;
}