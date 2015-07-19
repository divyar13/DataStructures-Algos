//longest chain (diameter = no. of nodes)
#include <stdio.h>
#define MAX 100

int adj[MAX][MAX]={0};
int depth[MAX];
int visited[MAX];

void getDepth(int node,int V)
{
    //printf("%d ",node);
    int i;
    int count=0;
    for(i=1;i<=V;i++)
    {
        if(adj[node][i]==1 && visited[i]==0)
        {
            count++;
            visited[i]=1;
            depth[i]=1+depth[node];
            //printf("%d %d\n",i,depth[i]);
            getDepth(i,V);
        }
    }
    if(count==0)
    {
        return;
    }
}

int main()
{
    int i,j,V,E;

    printf("Enter no. of vertices and edges : ");
    scanf("%d%d",&V,&E);

    //int from[20];
    //int to[20];

    int a,b;


    for(i=1;i<=E;i++)
    {
        scanf("%d%d",&a,&b);//alphabetical, directed/undirected edges
        adj[a][b]=1;
        adj[b][a]=1;
    }

    /*for(i=1;i<=V;i++)
    {
        for(j=1;j<=V;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }*/
    printf("\n");

    visited[1]=1;
    getDepth(1,V);

    int max=0,maxV;

    printf("\nIntermediate Depth:\n");
    for(i=1;i<=V;i++)
    {
        //printf("%d %d\n",i,depth[i]);
        if(depth[i]>max)
        {
            max=depth[i];
            maxV=i;
        }
        depth[i]=0;
        visited[i]=0;
    }

    printf("MaxV = %d\n",maxV);
    visited[maxV]=1;
    getDepth(maxV,V);


    printf("\nFinal depth: \n");
    max=0;
    for(i=1;i<=V;i++)
    {
        //printf("%d %d\n",i,depth[i]);
        if(depth[i]>max)
        {
            max=depth[i];
        }
    }
    printf("%d",max+1);


    return 0;
}
