#include <stdio.h>
#define MAX 1000 //max no. of elements in input array
#define MINVAL 0
#define MAXVAL 1000 //Assuming all values in the array lie between MINVAL and MAXVAL, both inclusive

void countingSort(int A[], int n, int *C[])
{
    int i;
    int k=MAXVAL-MINVAL+1;
    int B[MAXVAL-MINVAL+1]={0}; //frequency array

    for(i=0;i<n;i++)
    {
        B[A[i]-MINVAL]++;
    }
    for(i=1;i<=k;i++)
    {
        B[i]=B[i]+B[i-1];
    }

    for(i=n-1;i>=0;i--)
    {
        C[B[A[i]-MINVAL]-1]=A[i];
        B[A[i]-MINVAL]--;
    }
}

int main()
{
    int A[MAX];
    int B[MAX]; //sorted array

    int n;
    int k=MAXVAL-MINVAL+1;

    printf("Enter no. of elements in array: ");
    scanf("%d", &n);
    printf("Enter elements in array:\n");

    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    countingSort(A,n,B);

    printf("Sorted array:\n");

    for(i=0;i<n;i++)
    {
        printf("%d ",B[i]);
    }

    return 0;

}
