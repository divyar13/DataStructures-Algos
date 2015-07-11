#include <stdio.h>

int Partition(int* A[], int i, int j)
{
    int sm=i-1;
    int pv=A[j];

    int k,temp;
    for(k=i;k<j;k++)
    {
        if(A[k]<=pv)
        {
            temp=A[sm+1];
            A[sm+1]=A[k];
            A[k]=temp;
            sm++;
        }
    }
    A[j]=A[sm+1];
    A[sm+1]=pv;

    return sm+1;
}

void quickSort(int** A,int i,int j)
{
    if(i<j)
    {
        int p=Partition(A,i,j);
        quickSort(A,i,p-1);
        quickSort(A,p+1,j);
    }
}

int main()
{
    printf("Enter size of array: ");
    int n,i,j;
    int A[100];

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    quickSort(A,0,n-1);

    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}
