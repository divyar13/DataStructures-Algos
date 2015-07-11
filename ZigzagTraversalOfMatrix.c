#include <stdio.h>
#define MAX 100

/*
    R=3, C=5

    1  2  3  4  5
    10 9  8  7  6
    11 12 13 14 15

    traversal: 1 2 3 4 5 6 7 8 9 10 11 12 13 14
*/

int main()
{
    int A[MAX][MAX];
    int R,C;
    printf("Enter no. of rows and columns in matrix: ");
    scanf("%d%d", &R,&C);

    printf("Enter elements in array:\n");

    int i,j;
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }

    printf("Traversal:\n");

    i=0;
    j=0;
    for(i=0;i<R;i++)
    {
        //even row - L2R
        if(i%2 == 0)
        {
            for(j=0;j<C;j++)
            {
                printf("%d ",A[i][j]);
            }
        }
        else //odd row - R2L
        {
            for(j=C-1;j>=0;j--)
            {
                printf("%d ",A[i][j]);
            }
        }
    }

    return 0;
}
