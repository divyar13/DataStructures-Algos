#include <stdio.h>
#define MAX 100

struct Queue
{
    int front;
    int rear;
    int Q[MAX];
};

struct Queue queue;

void enqueue(int key)
{
    queue.Q[++queue.rear]=key;
}

int dequeue()
{
    return queue.Q[++queue.front];
}

int main()
{
    int i,j,V,E;

    printf("Enter no. of vertices and edges : ");
    scanf("%d%d",&V,&E);

    //int from[20];
    //int to[20];

    int a,b;

    int adj[MAX][MAX]={0};

    for(i=1;i<=E;i++)
    {
        scanf("%d%d",&a,&b);//alphabetical, directed edges
        adj[a][b]=1;
        //adj[b][a]=1;
    }

    for(i=1;i<=V;i++)
    {
        for(j=1;j<=V;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }

    int visited[MAX]={0};
    queue.front=-1;
    queue.rear=-1;

    int k=3;//starting node
    enqueue(k);
    visited[k]=1;

    while(queue.front!=queue.rear)
    {
        k=dequeue();
        printf("%d ",k);

        for(i=1;i<=V;i++)
        {
            if(adj[k][i]==1 && visited[i]==0)
            {
                enqueue(i);
                visited[i]=1;

            }
        }


    }

    return 0;
}
