#include <stdio.h>

int fact(int n)
{
    int f=1,i;
    for(i=1;i<=n;i++)
        f=f*i;
    return f;
}

int main()
{
    int n,i,j,k;
    float x[10],fd[10][10],xp,h,s,p,v;

    printf("Enter number of points: ");
    scanf("%d",&n);

    printf("Enter value of x where interpolation is required: ");
    scanf("%f",&xp);

    for(i=0;i<n;i++)
    {
        printf("Enter x and f(x) at i=%d: ",i);
        scanf("%f %f",&x[i],&fd[i][0]);
    }

    h = x[1] - x[0];
    s = (xp - x[0]) / h;

    /* Generate Forward Difference Table */
    for(j=1;j<n;j++)
    {
        for(i=0;i<n-j;i++)
        {
            fd[i][j] = fd[i+1][j-1] - fd[i][j-1];
        }
    }

    /* Print Forward Difference Table */
    printf("\nForward Difference Table:\n");
    printf("x\tf(x)");
    for(i=1;i<n;i++)
        printf("\tD^%d",i);
    printf("\n");

    for(i=0;i<n;i++)
    {
        printf("%f\t",x[i]);
        for(j=0;j<n-i;j++)
        {
            printf("%f\t",fd[i][j]);
        }
        printf("\n");
    }

    /* Newton Forward Formula */
    v = fd[0][0];

    for(i=1;i<n;i++)
    {
        p = 1;
        for(k=1;k<=i;k++)
            p = p * (s-k+1);

        v = v + (fd[0][i] * p) / fact(i);
    }

    printf("\nInterpolated value = %f\n",v);

    return 0;
}