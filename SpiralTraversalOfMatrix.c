#include <stdio.h>
#define MAX 100

/*
    R=3, C=5

    1  2  3  4  5
    12 13 14 15 6
    11 10 9  8  7

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

    int rowStart=0, rowEnd=R, colStart=0, colEnd=C;
    i=0;
    j=0;
    int count=0;
    int H=0;

    while(count < R*C)
    {
        if(H == 0) //even: horizontal (L2R)
        {
            for(i=colStart;i<colEnd;i++)
            {
                printf("%d ", A[rowStart][i]);
                count++;
            }
            rowStart++;
            H=(H+1)%4;
        }
        else if(H == 1) //odd: vertical (U2D)
        {
            for(i=rowStart;i<rowEnd;i++)
            {
                printf("%d ", A[i][colEnd-1]);
                count++;
            }
            colEnd--;
            H=(H+1)%4;
        }
        else if(H == 2) //even: horizontal (R2L)
        {
            for(i=colEnd-1;i>=colStart;i--)
            {
                printf("%d ", A[rowEnd-1][i]);
                count++;
            }
            rowEnd--;
            H=(H+1)%4;
        }
        else //odd: vertical (D2U)
        {
            for(i=rowEnd-1;i>=rowStart;i--)
            {
                printf("%d ", A[i][colStart]);
                count++;
            }
            colStart++;
            H=(H+1)%4;
        }

    }

    return 0;
}
