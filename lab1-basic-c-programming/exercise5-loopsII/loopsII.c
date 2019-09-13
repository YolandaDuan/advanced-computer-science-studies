#include <stdio.h>
#include <string.h>

int main (int argc, char ** argv) {
    int i, n;
    printf("Give a number: ");
    scanf("%d", &n);
    for(i = 1; i < n+1; i++){
        printf("%d \n", i);
    }

    int tf = 1;
    while(tf){
        printf("Run again (y/n)? ");
        char c[5];
        int result;
        scanf("%s", c);
        result = strncmp(c, "y", 1);
        if (!result){
            int p, q;
            printf("Give a number: ");
            scanf("%d", &p);
            for(q = 1; q < p+1; q++){
                 printf("%d \n", q);
            }
        }
        else{
            tf = 0;
            printf("Exiting... \n");
        }
    }

    return 0;
}