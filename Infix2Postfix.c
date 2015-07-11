#include <stdio.h>

struct stack
{
    int top;
    char val[100];
};

struct stack S;

void push(char key)
{
    S.val[++S.top]=key;
}

char pop()
{
    return S.val[S.top--];
}

int main()
{
    char expr[100];
    printf("Enter infix expression: ");
    //Expression has to be enclosed in ( ) (No other brackets allowed)
    //Only single digits,+,-,*,/ allowed. No spaces
    gets(expr);

    int len;
    for(len=0;expr[len]!='\0';len++);
    printf("len = %d\n",len);
    printf("%s\n",expr);

    S.top=-1;

    char postfix[100]={0};
    int k=0;
    char temp;
    int i=0,j;

    while(i<len)
    {
        //printf("%c\n",expr[i]);
        if(expr[i]=='(')
        {
            push(expr[i]);
        }
        else if(expr[i]>='0' && expr[i]<='9')
        {
            postfix[k++]=expr[i];
        }
        else if(expr[i]==')')
        {
            temp=pop();
            while(temp!='(')
            {
                postfix[k++]=temp;
                temp=pop();
            }
            //pop();//removing (
        }
        else
        {
            if(expr[i]=='*' || expr[i]=='/')
            {
                while(S.val[S.top]=='*' || S.val[S.top]=='/')
                {
                    temp=pop();
                    postfix[k++]=temp;
                }

                push(expr[i]);
            }
            else if(expr[i]=='+' || expr[i]=='-')
            {
                while(S.val[S.top]=='*' || S.val[S.top]=='/' || S.val[S.top]=='+' || S.val[S.top]=='-')
                {
                    temp=pop();
                    postfix[k++]=temp;

                }
                push(expr[i]);
            }
        }
        i++;
    }

    postfix[k]='\0';

    printf("%s ",postfix);

    return 0;
}


