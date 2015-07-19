#include <stdio.h>

int main()
{
    char num1[100];
    char num2[100];

    int result[200]={0};

    printf("Enter number1 : ");
    gets(num1);
    printf("Enter number2 : ");
    gets(num2);

    int i,j,k=0;
    int len1,len2;

    for(len1=0;num1[len1]!='\0';len1++);
    for(len2=0;num2[len2]!='\0';len2++);


    int temp;

    for(i=len1-1;i>=0;i--)
    {
        k=len1-1-i;
        for(j=len2-1;j>=0;j--)
        {
            temp = (num1[i]-'0')*(num2[j]-'0');
            result[k++]+=temp;
            printf("%d ",temp);
            /*if(temp<=9)
            {
                result[k]+=temp;
            }
            else
            {
                result[k++]+=(temp%10)+'0';
                result[k]+=(temp/10)+'0';
            }*/

        }
    }

    printf("\n");

    for(i=0;i<=k;i++)
    {
        if(result[i]>9)
        {
            temp=result[i];
            result[i]=temp%10;
            result[i+1]+=temp/10;
            printf("%d ",result[i]);
        }
    }

    printf("\n");

    for(i=k;i>=0;i--)
    {
        printf("%d",result[i]);
    }

    return 0;
}
