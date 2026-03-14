#include <stdio.h>

float f(float x, float y)
{
    return x + y;   //  dy/dx = x + y
}

int main()
{
    float x0,y0,h,xn;
    float x,y;

    printf("Enter initial value x0 and y0: ");
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
        y = y + h*f(x,y);
        x = x + h;

        printf("\t%f\t%f\n",x,y);
    }

    printf("\nApproximate solution y(%f) = %f\n",xn,y);

    return 0;
}