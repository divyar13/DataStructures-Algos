#include <stdio.h>
#define MAX 100

struct Stack
{
    int top;
    int S[MAX];
};

struct Stack stack;

void push(int key)
{
    stack.S[++stack.top]=key;
}

int pop()
{
    return stack.S[stack.top--];
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
    stack.top=-1;

    int k=3;//starting node
    push(k);
    visited[k]=1;

    while(stack.top!=-1)
    {
        k=pop();
        printf("%d ",k);

        for(i=1;i<=V;i++)
        {
            if(adj[k][i]==1 && visited[i]==0)
            {
                push(i);
                visited[i]=1;

            }
        }


    }

    return 0;
}
