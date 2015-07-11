//longest chain (diameter = no. of nodes)
#include <stdio.h>
#define MAX 100

int adj[MAX][MAX]={0};

int main()
{
    int i,j,V,E;

    printf("Enter no. of vertices and edges : ");
    scanf("%d%d",&V,&E);

    //int from[20];
    //int to[20];

    int a,b;


    int parent[MAX];
    for(i=1;i<=V;i++)
    {
        parent[i]=i;
    }

    for(i=1;i<=E;i++)
    {
        scanf("%d%d",&a,&b);//alphabetical, directed/undirected edges
        adj[a][b]=1;
        adj[b][a]=1;//commented for directed graph

        //undirected graph
        if(a<b)
        {
            parent[b]=parent[a];
        }
        else
        {
            parent[a]=parent[b];
        }

        //parent[b]=parent[a]; //only this statement for directed graph

    }

    for(i=1;i<=V;i++)
    {
        printf("%d %d\n",i,parent[i]);
    }


    return 0;
}
