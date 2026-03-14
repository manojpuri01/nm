#include <stdio.h>

int main()
{
    int i,n;
    float x[20],y[20],h,sum1=0,sum2=0,I;

    printf("Enter number of intervals (even): ");
    scanf("%d",&n);

    printf("Enter values of x and y:\n");
    for(i=0;i<=n;i++)
    {
        scanf("%f %f",&x[i],&y[i]);
    }

    h = x[1] - x[0];

    for(i=1;i<n;i++)
    {
        if(i%2==0)
            sum2 += y[i];
        else
            sum1 += y[i];
    }

    I = (h/3)*(y[0] + y[n] + 4*sum1 + 2*sum2);

    printf("\nValue of integration = %f\n",I);

    return 0;
}