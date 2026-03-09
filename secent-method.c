#include <stdio.h>
#include <math.h>

#define F(x) (2*x*x + 4*x - 10)

int main()
{
    float x0,x1,x2,f0,f1,E,Er;
    int i=1;

    printf("Enter initial guesses x0 and x1: ");
    scanf("%f %f",&x0,&x1);

    printf("Enter precision E: ");
    scanf("%f",&E);

    printf("\nIter\t   x0\t\tx1\t\tx2\t\tf(x2)\n");

    while(1)
    {
        f0 = F(x0);
        f1 = F(x1);

        x2 = x1 - (f1*(x1-x0))/(f1-f0);

        printf("%d\t%f\t%f\t%f\t%f\n",i,x0,x1,x2,F(x2));

        Er = fabs((x2-x1)/x2);

        if(Er < E)
            break;

        x0 = x1;
        x1 = x2;
        i++;
    }

    printf("\nRoot = %f\n",x2);

    return 0;
}