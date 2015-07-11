#include <stdio.h>

int min(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    int V[6]={1,5,7,13,18,23};//value of coins
    printf("Enter N: ");
    int N;
    while(1)
    {
        scanf("%d",&N);

        int M[100];
        int i,j;

        for(i=2;i<100;i++)
        {
            M[i]=1000;
        }
        M[0]=0;
        M[1]=1;

        for(i=2;i<=N;i++)
        {
            for(j=0;j<6;j++)//6: no. of types of coins
            {
                if(i-V[j]>=0)
                    M[i]=min(M[i],M[i-V[j]]);
            }
            M[i]+=1;
        }

        printf("%d\n",M[N]);
    }


    return 0;
}
