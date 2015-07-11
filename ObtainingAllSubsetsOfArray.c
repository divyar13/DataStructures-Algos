#include <stdio.h>
#define MAX 1000
#define MAXVAL 999999 //value known to be larger than input elements


int main()
{
    int A[MAX];

    int n;

    printf("Enter no. of elements in array: ");
    scanf("%d", &n);
    printf("Enter elements in array:\n");

    int i,j;
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    for(i=1;i<=1<<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i & (1<<j))
            {
                printf("%d ",A[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
