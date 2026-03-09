#include <stdio.h>

int main()
{
    int n,i;
    float a[100],b[100],x;

    printf("Enter degree of polynomial: ");
    scanf("%d",&n);

    printf("Enter coefficients of polynomial:\n");
    for(i=n;i>=0;i--)
        scanf("%f",&a[i]);

    printf("Enter value of x: ");
    scanf("%f",&x);

    b[n]=a[n];

    printf("\nIteration\n");
    printf("i\tb[i]\n");

    for(i=n-1;i>=0;i--)
    {
        b[i]=a[i]+b[i+1]*x;
        printf("%d\t%f\n",i,b[i]);
    }

    printf("\nValue of polynomial p(%0.2f) = %0.2f\n",x,b[0]);

    return 0;
}