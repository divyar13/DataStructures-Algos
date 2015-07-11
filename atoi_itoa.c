#include <stdio.h>

int atoi(char str[], int len, int sign)
{
    char c;
    int num=0;
    int k=sign;
    int s=0;

    while(k<len)
    {
        c=str[k];
        if(c>='0' && c<='9')
        {
            s=s*10+(c-'0');
            k++;
        }

    }
    if(sign==0)
    {
        return s;
    }
    else
    {
        return -s;
    }
}

void itoa(int N, int sign, char* str[])
{
    int n=N;
    int s=0;
    int t;
    int k=sign;

    while(n>0)
    {
        t=n%10;
        n=n/10;
        str[k]=t+'0';
        k++;
    }
    int i;

    str[k]='\0';
    puts(str);

    char temp;

    int len;
    for(len=0;str[len]!='\0';len++);


    for(i=sign;i<len/2;i++)
    {
        temp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=temp;
    }
    if(sign==1)
    {
        str[0]='-';
    }
}

int main()
{
    printf("Enter no.: ");
    char str[100];
    gets(str);

    int len;
    for(len=0;str[len]!='\0';len++);

    int sign;
    if(str[0]=='-')
    {
        sign=1;
    }
    else
    {
        sign=0;
    }

    int N=atoi(str,len,sign);

    printf("Int : %d\n",N);

    char strN[100];
    itoa(N,sign,&strN);

    printf("String: %s\n",str);


}
