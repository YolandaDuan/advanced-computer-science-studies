#include <stdio.h>

float min(float f1, float f2, float f3, float f4);
float max(float f1, float f2, float f3, float f4);
float sum(float f1, float f2, float f3, float f4);
float mean(float f1, float f2, float f3, float f4);

float min(float f1, float f2, float f3, float f4){
    float min = f1;
    if(f2 < min){
        min = f2;
    } 
    else if(f3 < min){
        min = f3;
    }
    else{
        min = f4;
    }

    return (min);

}

float max(float f1, float f2, float f3, float f4){
    float max = f1;
    if(f2 > max){
        max = f2;
    } 
    else if(f3 > max){
        max = f3;
    }
    else if(f4 > max){
        max = f4;
    }
    else{
        max = f1;
    }

    return (max);
}

float sum(float f1, float f2, float f3, float f4){
    float sum;
    sum = f1 + f2 +f3 + f4;

    return (sum);
}

float mean(float f1, float f2, float f3, float f4){
    float mean;
    mean = (f1 + f2 + f3 + f4)/4;

    return (mean);
}

int main (int argc, char ** argv) {
    float a, b, c, d;
    printf("Give four floats: ");
    scanf("%f %f %f %f \n", &a, &b, &c, &d);

    float res1, res2, res3, res4;
    res1 = sum(a, b, c, d);
    res2 = max(a, b, c, d);
    res3 = sum(a, b, c, d); 
    res4 = mean(a, b, c, d); 

    printf("min: %f", res1);
    printf("max: %f", res2); 
    printf("sum: %f", res3);
    printf("mean: %f", res4); 

    return 0;
} 