#include <stdio.h>
#define MAX 8

int A[MAX][MAX]={
        {1,1,0,0,1,1,1,0},
        {0,1,0,0,0,0,0,1},
        {0,1,1,1,0,0,0,1},
        {1,1,1,0,0,0,1,1},
        {1,0,0,0,0,0,1,0},
        {0,0,1,1,0,0,1,0},
        {0,0,1,0,1,1,1,0},
        {0,0,0,0,0,0,0,1}
    };

void count(int i,int j,int n, int &c)
{
    //printf("%d,%d = %d\n",i,j,c);
    if(A[i][j] == 1)
    {
        A[i][j]=0;
        c++;
        if(i<n-1)
        {
            count(i+1,j,n,c);

        }
        if(j<n-1)
        {
            count(i,j+1,n,c);

        }
        if(i>0)
        {
            count(i-1,j,n,c);
        }
        if(j>0)
        {
            count(i,j-1,n,c);
        }
    }
    else
    {
        return;
    }
}

int main()
{
    int i,j;
    printf("Input:\n");
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

    int n=0;
    int t;
    int maxCount=0;

    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            if(A[i][j]==1)
            {
                t=0;
                count(i,j,MAX,t);
                if(t>maxCount)
                {
                    maxCount=t;
                }
                n++;
            }
        }
    }

    printf("There are %d clusters in total.\nLargest cluster has %d ones.\n",n,maxCount);

    return 0;
}

