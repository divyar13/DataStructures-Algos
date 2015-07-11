#include <stdio.h>
#define MAX 1000
#define MAXVAL 999999 //value known to be larger than input elements

void mergeSort(int* A[], int start, int mid, int end)
{
    int leftSize=mid-start+1;
    int rightSize=end-mid;

    int leftArr[MAX/2 + 1];
    int rightArr[MAX/2 + 1];

    int i;
    for(i=start;i<=mid;i++)
    {
        leftArr[i-start]=A[i];
    }
    leftArr[leftSize]=MAXVAL;

    for(i=mid+1;i<=end;i++)
    {
        rightArr[i-(mid+1)]=A[i];
    }
    rightArr[rightSize]=MAXVAL;

    int leftIdx=0, rightIdx=0;

    for(i=start; i<=end; i++)
    {
        if(leftArr[leftIdx] <= rightArr[rightIdx])
        {
            A[i]=leftArr[leftIdx];
            leftIdx++;
        }
        else
        {
            A[i]=rightArr[rightIdx];
            rightIdx++;
        }
    }
}

void Partition(int* A[], int start, int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        Partition(A,start,mid);
        Partition(A,mid+1,end);
        mergeSort(A,start,mid,end);
    }
}

int main()
{
    int A[MAX];

    int n;

    printf("Enter no. of elements in array: ");
    scanf("%d", &n);
    printf("Enter elements in array:\n");

    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    Partition(A,0,n-1);

    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }

    return 0;
}
