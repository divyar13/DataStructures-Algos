#include <stdio.h>

int main()
{
    char str[100]={0};
    char substr[100]={0};
    int temp;

    printf("Enter string: ");
    gets(str);

    int strlen;
    for(strlen=0; str[strlen]!='\0'; strlen++);

    printf("Enter substring: ");
    gets(substr);

    int substrlen;
    for(substrlen=0; substr[substrlen]!='\0'; substrlen++);

    printf("strlen = %d\nsubstrlen = %d\n\n", strlen, substrlen);

    int i,j;
    int sub[100];

    for(i=0; i<substrlen; i++)
    {
        sub[i]=substrlen-i-1;
        //printf("%d %d\n",i,sub[i]);
    }

    int flag=0;
    int c=0;
    int k=substrlen-1;
    int r;

    i=substrlen-1;
    while(i<strlen && i>=0)
    {
        //printf("i = %d\n",i);
        //scanf("%d",&temp);
        if(str[i]==substr[k])
        {
            while(i>=0 && k>=0 && str[i]==substr[k])
            {
                k--;
                i--;
                c++;
                if(c==substrlen)
                {
                    flag=1;
                    printf("Present\n");
                    printf("Position: %d in original string\n",i+1);
                    return 0;
                }
            }

        }
        else
        {
            c=0;
            k=substrlen-1;
            r=substrlen;

            for(j=substrlen-1;j>=0;j--)
            {
                if(substr[j]==str[i])
                {
                    //printf("substr[%d] = %d\n",j,substr[j]);
                    r=sub[j];
                    break;
                }
            }
            i=i+r;

            //printf("new r: %d\n",r);
        }

    }
    printf("Not Present\n");

    return 0;

}

