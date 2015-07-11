//colour the nodes red and blue
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
        scanf("%d%d",&a,&b);//alphabetical, directed/undirected edges
        adj[a][b]=1;
        adj[b][a]=1;
    }

    for(i=1;i<=V;i++)
    {
        for(j=1;j<=V;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int visited[MAX]={0};
    int colour[MAX]={0};
    //R=1
    //B=2
    queue.front=-1;
    queue.rear=-1;

    int k=1;//starting node
    enqueue(k);
    visited[k]=1;
    colour[k]=1;//starting with red
    int flag=0;
    int c;

    while(queue.front!=queue.rear)
    {
        k=dequeue();
        //printf("%d ",k);
        c=colour[k];

        for(i=1;i<=V;i++)
        {
            if(adj[k][i]==1)
            {
                if(colour[i]==c)//adjacent nodes shouldn't be assigned the same colour
                {
                    flag=1;
                    printf("Not Bipartite\n");
                    return 0;
                }

                if(colour[i]==0)
                {
                    if(c==1)//red
                    {
                        colour[i]=2;//blue
                    }
                    else
                    {
                        colour[i]=1;//red
                    }
                }
                if(visited[i]==0)
                {
                    enqueue(i);
                    visited[i]=1;
                }


            }
        }

    }

    printf("\n");
    for(i=1;i<=V;i++)
    {
        printf("%d %d\n",i,colour[i]);
    }

    return 0;
}
