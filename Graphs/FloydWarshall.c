#include <stdio.h>

#define INF 9999999

int min(int a,int b)
{
    return a<=b ? a:b;
}

int main()
{
    int i,j,V,E;

    printf("Enter no. of vertices and edges : ");
    scanf("%d%d",&V,&E);

    //int from[20];
    //int to[20];

    int a,b,wt;
    int adj[100][100]={0};
    int W[100][100];


    for(i=1;i<=E;i++)//nodes starting from 1
    {
        scanf("%d%d%d",&a,&b,&wt);//alphabetical, directed/undirected edges
        adj[a][b]=wt;
        //adj[b][a]=1;
    }

    for(i=1;i<=V;i++)
    {
        for(j=1;j<=V;j++)
        {
            if(adj[i][j]==0)
            {
                W[i][j]=INF;//no edge
            }
            else
            {
                W[i][j]=adj[i][j];
            }
        }

    }

    int k;
    for(k=1;k<=V;k++)
    {
        for(i=1;i<=V;i++)
        {
            for(j=1;j<=V;j++)
            {
                W[i][j]=min(W[i][j],W[i][k]+W[k][j]);//finds shortest path from i to j using vertices from 1,2,...,k
            }
        }
    }

    for(i=1;i<=V;i++)
    {
        for(j=1;j<=V;j++)
        {
            printf("%d ",W[i][j]);
        }
        printf("\n");
    }

    return 0;

}
