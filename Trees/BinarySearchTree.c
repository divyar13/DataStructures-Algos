#include <stdio.h>

struct node
{
    int val;
    int left;
    int right;
    int parent;
};

struct node Tree[100];
int root=-1;
int ptr;

void insertNode(int key)
{
    if(root==-1)//empty tree
    {
        root=1;
        ptr=root;
        Tree[ptr].val=key;
        Tree[ptr].left=0;
        Tree[ptr].right=0;
        Tree[ptr].parent=0;
        ptr++;
    }
    else
    {
        int idx=root;
        int idxsaved;

        while(idx!=0)
        {
            idxsaved=idx;
            if(key <= Tree[idx].val)//left
            {
                idx=Tree[idx].left;
            }
            else
            {
                idx=Tree[idx].right;
            }
        }
        //printf("idxsaved = %d\n",idxsaved);

        Tree[ptr].val=key;
        Tree[ptr].parent=idxsaved;
        Tree[ptr].left=0;
        Tree[ptr].right=0;

        if(key <= Tree[idxsaved].val)
        {
            Tree[idxsaved].left=ptr;
        }
        else
        {
            Tree[idxsaved].right=ptr;
        }
        ptr++;

    }


}

void preorder(int idx)
{
    if(idx!=0)
    {
        printf("%d ",Tree[idx].val);
        preorder(Tree[idx].left);
        preorder(Tree[idx].right);
    }
}

void inorder(int idx)
{
    if(idx!=0)
    {
        inorder(Tree[idx].left);
        printf("%d ",Tree[idx].val);
        inorder(Tree[idx].right);
    }
}

void postorder(int idx)
{
    if(idx!=0)
    {
        postorder(Tree[idx].left);
        postorder(Tree[idx].right);
        printf("%d ",Tree[idx].val);
    }
}

int main()
{
    int N;
    printf("Enter no. of nodes: ");
    scanf("%d",&N);

    int i;
    int temp;
    for(i=1;i<=N;i++)
    {
        scanf("%d",&temp);
        insertNode(temp);

    }

    inorder(1);
}
