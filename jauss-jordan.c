#include <stdio.h>

int main()
{
    int i,j,k,n;
    float a[10][20],ratio;

    printf("Enter number of variables: ");
    scanf("%d",&n);

    printf("Enter the augmented matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
        {
            scanf("%f",&a[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                ratio=a[j][i]/a[i][i];
                for(k=0;k<=n;k++)
                {
                    a[j][k]=a[j][k]-ratio*a[i][k];
                }
            }
        }
    }

    printf("\nSolution:\n");

    for(i=0;i<n;i++)
    {
        printf("x%d = %f\n",i+1,a[i][n]/a[i][i]);
    }

    return 0;
}