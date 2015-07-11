#include <stdio.h>

int max(int a,int b)
{
    return a>=b?a:b;
}


void getSequence(int length[100][100], char direction[100][100], int i, int j, char* x, char* y)
{
    if(i>=0 && j>=0)
    {
        if(direction[i][j]=='D')
        {
            getSequence(length,direction,i-1,j-1,x,y);
            printf("%c",x[i]);
        }
        else if(direction[i][j]=='U')
        {
            getSequence(length,direction,i-1,j,x,y);
        }
        else
        {
            getSequence(length,direction,i,j-1,x,y);
        }

    }

}

int main()
{
    printf("Enter 2 strings:\n");
    char x[100];
    char y[100];

    gets(x);
    gets(y);

    int lenx,leny;
    int i,j;

    for(lenx=0;x[lenx]!='\0';lenx++);
    for(leny=0;y[leny]!='\0';leny++);

    char direction[100][100];
    int length[100][100]={0};


    for(i=0;i<lenx;i++)
    {
        for(j=0;j<leny;j++)
        {
            if(x[i]==y[j])
            {

                length[i+1][j+1]=length[i][j]+1;
                direction[i][j]='D';


            }
            else
            {
                length[i+1][j+1]=max(length[i][j+1],length[i+1][j]);

                if(length[i+1][j+1]==length[i][j+1])
                {
                    direction[i][j]='U';
                }
                else
                {
                    direction[i][j]='L';
                }
            }
        }
    }

    /*for(i=0;i<lenx;i++)
    {
        for(j=0;j<leny;j++)
        {
            printf("%c ",direction[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i=1;i<=lenx;i++)
    {
        for(j=1;j<=leny;j++)
        {
            printf("%d ",length[i][j]);
        }
        printf("\n");
    }

    int max=0,maxi,maxj;
    for(i=0;i<=lenx;i++)
    {
        for(j=0;j<=leny;j++)
        {
            if(length[i][j]>max)
            {
                maxi=i;
                maxj=j;
                max=length[i][j];
            }
        }
    }

    printf("Max length = %d\ni = %d\nj = %d\n",max,maxi,maxj);
    */
    getSequence(length,direction,lenx-1,leny-1,x,y);

}
