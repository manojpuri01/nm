#include <stdio.h>
#include <math.h>

#define F(x) (x*x + 4*x - 9)
#define FD(x) (2*x + 4)

int main()
{
    float x0,x1,E,Er;
    int i=1;

    printf("Enter initial guess: ");
    scanf("%f",&x0);

    printf("Enter precision: ");
    scanf("%f",&E);

    printf("\nIter\t   x0\t\tx1\t\terror\n");

    while(1)
    {
        x1 = x0 - F(x0)/FD(x0);

        Er = fabs((x1-x0)/x1);

        printf("%d\t%f\t%f\t%f\n",i,x0,x1,Er);

        if(Er < E)
            break;

        x0 = x1;
        i++;
    }

    printf("\nRoot = %f\n",x1);

    return 0;
}