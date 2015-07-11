#include<stdio.h>
#define MAX 100

int max(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

int main()
{
    int n,i,j;
    //int A[MAX];
    int A[] =  {0,-2, -3, 4, -1, -2, 1, 5, -3};
    int L[MAX];
    int index[MAX];

    n=8;

    /*scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%d",&A[i]);
    }*/

    printf("A:\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");

    L[1]=A[1];
    int temp;
    int t;

    int maxVal=-999,maxIdx=0;
    for(i=1;i<=n-1;i++)
    {
        L[i+1]=max(A[i+1],L[i]+A[i+1]);
        if(L[i]>maxVal)
        {
            maxVal=L[i];
            maxIdx=i;
        }
    }


    for(i=1;i<=n;i++)
    {
        printf("%d ",L[i]);
    }
    printf("\n\n");

    int idx=maxIdx;
    int count=maxVal;
    while(count>0)
    {
        count-=A[idx];
        printf("%d ",A[idx]);

        idx--;

    }



    return 0;
}
