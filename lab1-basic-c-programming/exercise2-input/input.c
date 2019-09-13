#include <stdio.h>

int main (int argc, char ** argv) {
    int a, b, c;
    printf("Give two integers: ");
    scanf("%d %d", &a, &b);
    c = a + b;
    printf("You entered %d and %d, their sum is: %d \n", a, b, c);
    
    float f1, f2, f3;
    printf("Give two floats: ");
    scanf("%f %f", &f1, &f2);
    f3 = f1 * f2;
    printf("You entered %f and %f, their product is: %f \n", f1, f2, f3);

    char str[20];
    printf("Give a word: ");
    scanf("%s", str);
    printf("%s %s \n", str, str);
    
    return 0;
}