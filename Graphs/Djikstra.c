//colour the nodes red and blue
#include <stdio.h>
#define MAX 100


int min(int a,int b)
{
    return a<=b ? a:b;
}
struct Queue
{
    int front;
    int rear;
    int val[MAX];
};

struct Queue Q;

void enqueue(int key)
{
    Q.val[++Q.rear]=key;
}

int dequeue()
{
    return Q.val[++Q.front];
}

struct Stack
{
    int top;
    int val[MAX];
};

struct Stack S;

void push(int key)
{
    S.val[++S.top]=key;
}

int pop()
{
    return S.val[S.top--];
}

int main()
{
    int i,j,V,E;

    FILE* fp=fopen("graph.txt","r"); //for sample graph at http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/

    printf("Enter no. of vertices and edges : ");
    fscanf(fp,"%d%d",&V,&E);
    //scanf("%d%d",&V,&E);
    printf("V=%d, E=%d\n",V,E);

    //int from[20];
    //int to[20];

    int a,b,c;

    int adj[MAX][MAX];



     for(i=0;i<=V;i++)
     {
        for(j=0;j<=V;j++)
        {
            adj[i][j]=-1;
        }
     }

    for(i=1;i<=E;i++)
    {
        fscanf(fp,"%d%d%d",&a,&b,&c);//alphabetical, undirected edges (source, destination, weight)
        //scanf("%d%d%d",&a,&b,&c);
        adj[a][b]=c;
        adj[b][a]=c;
        //printf("%d %d %d\n",a,b,c);
    }

    //starting node=0



   /* for(i=0;i<=V;i++)
    {
        for(j=0;j<=V;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    } */

    int distance[MAX];
    int visited[MAX]={0};
    for(i=1;i<=V;i++)
    {
        distance[i]=999999;//infinity
    }
    distance[0]=0;
    int count=0;

    Q.front=-1;
    Q.rear=-1;

    int k=0;
    enqueue(k);


    while(count<=V)
    {
        k=dequeue();
        for(i=0;i<V;i++)
        {
            if(adj[k][i]>=0 && visited[i]==0)
            {
                //printf("dk=%d,di+adj[k][i]=%d\n",distance[k],distance[i]+adj[k][i]);
                distance[i]=min(distance[i],distance[k]+adj[k][i]);
                enqueue(i);
            }
        }
        visited[k]=1;
        count++;

    }

    for(i=0;i<V;i++)
        printf("%d %d\n",i,distance[i]);

    return 0;
}
