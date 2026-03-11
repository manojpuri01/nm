#include <stdio.h>
#include <math.h>

int main()
{
    int n,i,j;
    float a[10][10],x[10]={1,1,1},y[10],nx[10];
    float k,el=0.001;

    printf("Enter dimension of matrix: ");
    scanf("%d",&n);

    printf("Enter matrix coefficients row-wise:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%f",&a[i][j]);

    while(1)
    {
        for(i=0;i<n;i++)
        {
            y[i]=0;
            for(j=0;j<n;j++)
                y[i]+=a[i][j]*x[j];
        }

        k=fabs(y[0]);
        for(i=1;i<n;i++)
            if(fabs(y[i])>k)
                k=fabs(y[i]);

        for(i=0;i<n;i++)
            nx[i]=y[i]/k;

        int flag=1;
        for(i=0;i<n;i++)
            if(fabs(nx[i]-x[i])>el)
                flag=0;

        if(flag==1)
            break;

        for(i=0;i<n;i++)
            x[i]=nx[i];
    }

    printf("\nLargest Eigenvalue = %f\n",k);

    printf("Eigenvector:\n");
    for(i=0;i<n;i++)
        printf("%f\n",nx[i]);

    return 0;
}