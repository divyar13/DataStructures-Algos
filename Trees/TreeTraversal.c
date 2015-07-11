#include <stdio.h>
#define MAX 100
#define V 10 //no. of nodes = 10 (numbered from 0 to V-1)

int T[V][3] = {
        {0,-1,-1},
        {1,0,2},
        {2,-1,-1},
        {3,1,-1},
        {4,3,6},
        {5,-1,-1},
        {6,5,7},
        {7,-1,9},
        {8,-1,-1},
        {9,8,-1}
    }; //node,left,right

void preorder(int idx)
{
    if(idx!=-1)
    {
        printf("%d ",T[idx][0]);
        preorder(T[idx][1]);
        preorder(T[idx][2]);
    }
}

void inorder(int idx)
{
    if(idx!=-1)
    {
        inorder(T[idx][1]);
        printf("%d ",T[idx][0]);
        inorder(T[idx][2]);
    }
}

void postorder(int idx)
{
    if(idx!=-1)
    {
        postorder(T[idx][1]);
        postorder(T[idx][2]);
        printf("%d ",T[idx][0]);
    }
}

int LeastCommonAncestor(int idx, int key1, int key2) //For BST only
{
    if(key1<T[idx][0] && key2<T[idx][0])//left side of idx
    {
        return LeastCommonAncestor(T[idx][1],key1,key2);
    }
    else if(key1>T[idx][0] && key2>T[idx][0])//right side of idx
    {
        return LeastCommonAncestor(T[idx][2],key1,key2);
    }
    else
    {
        return idx;
    }
}

void mirror(idx)
{
    if(idx!=-1)
    {
        int temp=T[idx][1];
        T[idx][1]=T[idx][2];
        T[idx][2]=temp;
        mirror(T[idx][1]);
        mirror(T[idx][2]);
    }
}

int main()
{
    int count=0;


    int tree[V+1]={99999,4,3,6,7,1,9,0,2,8,5};
    //Root: 4
    printf("\nPreorder: ");
    preorder(4);
    printf("\nInorder: ");
    inorder(4);
    printf("\nPostorder: ");
    postorder(4);

    int key1=5,key2=8;
    printf("\n\nLeast Common Ancestor for %d and %d is: %d\n\n",key1,key2,LeastCommonAncestor(4,key1,key2));

    mirror(4);
    printf("After mirroring:\n");
    printf("\nPreorder: ");
    preorder(4);
    printf("\nInorder: ");
    inorder(4);
    printf("\nPostorder: ");
    postorder(4);

    return 0;
}
