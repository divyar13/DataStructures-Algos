#include <stdio.h>

/*E.g.
Input: 17
Output: 11101
*/

struct queue
{
    int front;
    int rear;
    int Q[100];
};

struct queue Q1;

void enqueue(int key)
{
    Q1.Q[++Q1.rear]=key;
}

int dequeue()
{
    return Q1.Q[++Q1.front];
}


int main()
{
    printf("Enter number: ");
    int n,i;
    scanf("%d",&n);

    Q1.front=-1;
    Q1.rear=-1;

    int v;
    enqueue(1);

    while(1)
    {
        v=dequeue();

        if(v%n==0)
            break;
        else
        {
            enqueue(v*10);
            enqueue(v*10+1);
        }

    }

    printf("%d\n",v);

    return 0;
}
