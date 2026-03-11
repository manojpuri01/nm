#include <stdio.h>

int fact(int n)
{
    int i,f=1;
    for(i=1;i<=n;i++)
        f=f*i;
    return f;
}

int main()
{
    int n,i,j;
    float x[10],y[10][10],xp,h,p,sum;

    printf("Enter number of data points: ");
    scanf("%d",&n);

    printf("Enter values of x and y:\n");
    for(i=0;i<n;i++)
        scanf("%f %f",&x[i],&y[i][0]);

    printf("Enter value of x for interpolation: ");
    scanf("%f",&xp);

    for(j=1;j<n;j++)
    {
        for(i=0;i<n-j;i++)
        {
            y[i][j]=y[i+1][j-1]-y[i][j-1];
        }
    }

    h=x[1]-x[0];
    p=(xp-x[0])/h;

    sum=y[0][0];

    for(i=1;i<n;i++)
    {
        float term=y[0][i];
        int k;

        for(k=0;k<i;k++)
            term=term*(p-k);

        sum=sum + term/fact(i);
    }

    printf("\nInterpolated value = %f\n",sum);

    return 0;
}