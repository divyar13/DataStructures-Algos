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
    int A[MAX];
    int L[MAX];
    int index[MAX];

    printf("Enter size of array: ");
    scanf("%d",&n);

    printf("Enter elements of array:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&A[i]);
    }

    L[0]=0;
    int temp;
    int t;


    for(i=1;i<=n;i++)
    {
        temp=-999;
        for(j=1;j<i;j++)
        {
            if(A[j]<A[i])
            {
                temp=max(temp,L[j]);
                if(temp==L[j])
                {
                    t=j;
                }

            }
        }
        if(temp==-999)
        {
            L[i]=1;
        }
        else
        {
            L[i]=temp+1;
        }
        index[i]=t;
    }

    int maxVal=0;
    int maxValIdx=0;
    for(i=1;i<=n;i++)
    {
        printf("%d %d\n",L[i],index[i]);
        if(L[i]>maxVal)
        {
            maxVal=L[i];
            maxValIdx=i;
        }
    }

    int count=maxVal;
    int idx=maxValIdx;
    while(count>0)
    {
        printf("%d ",A[idx]);
        idx=index[idx];
        count--;

    }

return 0;
}
