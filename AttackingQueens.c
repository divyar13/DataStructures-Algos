#include <stdio.h>

#define MAXN 100
/* Place N Queens in an NxN chess board such that they don't attack each other.
    Example: N=4
    _ _ Q _
    _ _ _ Q
    Q _ _ _
    _ Q _ _
*/

int C[MAXN][MAXN]={0};


int isPositionSafe(int x, int y, int N)
{
    int i,j;
    //check left
    for(i=0;i<y;i++)
    {
        if(C[x][i])
        {
            return 0;
        }
    }

    //check upper left diagonal
    for(i=x,j=y; i>=0 && j>=0; i--,j--)
    {
        if(C[i][j])
        {
            return 0;
        }
    }

    //check lower left diagonal
    for(i=x,j=y; i<N && j>=0; i++,j--)
    {
        if(C[i][j])
        {
            return 0;
        }
    }
    return 1;
}

int placeQueen(int col, int N)
{
    if(col==N)
    {
        return 1;
    }
    int i,j;
    for(i=0;i<N;i++)
    {
        if(isPositionSafe(i,col,N))
        {
            C[i][col]=1;
            //printf("%d,%d\n",i,col);

            if(placeQueen(col+1,N))
            {
                return 1;
            }
            //printf("Backtracking:\n");
            C[i][col]=0;
        }
    }

    return 0;

}


int main()
{
    printf("Enter N (<100): ");
    int N;
    scanf("%d",&N);

    placeQueen(0,N);

    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
