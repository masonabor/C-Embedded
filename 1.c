#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

float inputFloatNumber(const char string[]);
float firstFunction(float a, float d);
float secondFunction(float a);

int main(void) {
    float a = inputFloatNumber("Enter first number");
    float d = inputFloatNumber("Enter second number");
    float z1 = firstFunction(a, d);
    float z2 = secondFunction(a);
    printf("z1 = %f\n", z1);
    printf("z2 = %f\n", z2);
    return 0;
}

float inputFloatNumber(const char string[]) {
    float number;
    printf("%s\n", string);
    scanf("%f", &number);
    return number;
}

float firstFunction(float a, float d) {
    return (sin((M_PI / 2) + 3 * d))/(1 - sin(3*a - M_PI));
}

float secondFunction(float a) {
    return 1 / tan((5.0 / 4.0) * M_PI + (3.0 / 2.0) * a);
}