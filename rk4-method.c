#include <stdio.h>

float f(float x,float y)
{
    return x + y;   // example differential equation dy/dx = x + y
}

int main()
{
    float x0,y0,h,xn;
    float k1,k2,k3,k4;
    float x,y;

    printf("Enter initial values x0 and y0: ");
    scanf("%f %f",&x0,&y0);

    printf("Enter step size h: ");
    scanf("%f",&h);

    printf("Enter value of x for which y is required: ");
    scanf("%f",&xn);

    x = x0;
    y = y0;

    printf("\nIteration\tx\t\ty\n");

    while(x < xn)
    {
        k1 = h * f(x,y);
        k2 = h * f(x + h/2 , y + k1/2);
        k3 = h * f(x + h/2 , y + k2/2);
        k4 = h * f(x + h , y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
        x = x + h;

        printf("\t%f\t%f\n",x,y);
    }

    printf("\nApproximate solution y(%f) = %f\n",xn,y);

    return 0;
}