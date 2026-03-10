#include <stdio.h>
#include <math.h>

int main()
{
    int n,i,j,iter;
    float a[10][10],b[10],x[10],xnew[10],error,e;

    printf("Enter number of variables: ");
    scanf("%d",&n);

    printf("Enter coefficient matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%f",&a[i][j]);

    printf("Enter constants:\n");
    for(i=0;i<n;i++)
        scanf("%f",&b[i]);

    printf("Enter initial guess:\n");
    for(i=0;i<n;i++)
        scanf("%f",&x[i]);

    printf("Enter tolerance: ");
    scanf("%f",&e);

    iter=1;

    while(1)
    {
        for(i=0;i<n;i++)
        {
            float sum=0;
            for(j=0;j<n;j++)
            {
                if(i!=j)
                    sum += a[i][j]*x[j];
            }
            xnew[i]=(b[i]-sum)/a[i][i];
        }

        error=0;
        for(i=0;i<n;i++)
        {
            if(fabs(xnew[i]-x[i])>error)
                error=fabs(xnew[i]-x[i]);
        }

        printf("Iteration %d: ",iter);
        for(i=0;i<n;i++)
            printf("%f ",xnew[i]);
        printf("\n");

        if(error<e)
            break;

        for(i=0;i<n;i++)
            x[i]=xnew[i];

        iter++;
    }

    printf("\nSolution:\n");
    for(i=0;i<n;i++)
        printf("x%d = %f\n",i+1,xnew[i]);

    return 0;
}