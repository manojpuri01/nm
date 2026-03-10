#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x*x;   // example function f(x) = x^2
}

int main()
{
    float a,b;
    float x1=-0.57735, x2=0.57735;
    float t1,t2,I;

    printf("Enter lower limit a: ");
    scanf("%f",&a);

    printf("Enter upper limit b: ");
    scanf("%f",&b);

    t1=((b-a)/2)*x1 + (a+b)/2;
    t2=((b-a)/2)*x2 + (a+b)/2;

    I=((b-a)/2)*(f(t1)+f(t2));

    printf("\nValue of integration = %f\n",I);

    return 0;
}