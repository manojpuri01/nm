#include <stdio.h>

int main()
{
    int n,i,j;
    float x,ax[10],fx[10],L[10],v=0,l;

    printf("Enter number of points: ");
    scanf("%d",&n);

    printf("Enter value of x: ");
    scanf("%f",&x);

    for(i=0;i<n;i++)
    {
        printf("Enter x and f(x) at i=%d: ",i);
        scanf("%f %f",&ax[i],&fx[i]);
    }

    printf("\nIteration\n");
    printf("i\tL[i]\tf(xi)*L[i]\n");

    for(i=0;i<n;i++)
    {
        l=1.0;

        for(j=0;j<n;j++)
        {
            if(j!=i)
            l=l*((x-ax[j])/(ax[i]-ax[j]));
        }

        L[i]=l;
        printf("%d\t%f\t%f\n",i,L[i],fx[i]*L[i]);
    }

    for(i=0;i<n;i++)
        v=v+fx[i]*L[i];

    printf("\nInterpolated value = %f\n",v);

    return 0;
}