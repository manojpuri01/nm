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
    float x[10],fx[10],fd[10],xp,h,s,p,v=0;

    printf("Enter number of points: ");
    scanf("%d",&n);

    printf("Enter value of x where interpolation is required: ");
    scanf("%f",&xp);

    for(i=0;i<n;i++)
    {
        printf("Enter x and f(x) at i=%d: ",i);
        scanf("%f %f",&x[i],&fx[i]);
    }

    h=x[1]-x[0];
    s=(xp-x[0])/h;

    for(i=0;i<n;i++)
        fd[i]=fx[i];

    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            fd[j]=fd[j]-fd[j-1];
        }
    }

    v=fd[0];

    for(i=1;i<n;i++)
    {
        p=1;
        for(k=1;k<=i;k++)
            p=p*(s-k+1);

        v=v+(fd[i]*p)/fact(i);
    }

    printf("\nInterpolated value = %f\n",v);

    return 0;
}