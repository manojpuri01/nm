#include <stdio.h>
#include <math.h>

#define f(x) (3*x*x - 6*x + 2)

int main()
{
    float a,b,c,E;
    int i=1;

    printf("Enter value of a: ");
    scanf("%f",&a);

    printf("Enter value of b: ");
    scanf("%f",&b);

    printf("Enter precision E: ");
    scanf("%f",&E);

    printf("\nIter\t a\t\t b\t\t c\t\t f(c)\n");

    while(fabs(a-b) > E)
    {
        c = (a+b)/2;

        printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\n",i,a,b,c,f(c));

        if(f(c)==0)
            break;

        else if(f(a)*f(c) < 0)
            b = c;

        else
            a = c;

        i++;
    }

    printf("\nRoot = %.6f\n",c);

    return 0;
}