#include <stdio.h>
int main()
{
    long long x=0,y=1,temp=0;
    long long m=0,n=0;
    int result;
    result=scanf("%lld %lld",&m,&n);
    if(result!=2)
    {
        return 1;
    }
    long long array[10000];
    int index=0;
    while(y<=n)
    {
        if(y>=m)
        {
            array[index]=y;
            index++;
        }
        temp=x;
        x=y;
        y+=temp;
    }
    for(int i=0;i<index;i++)
    {
        if(i==index-1)
        {
            printf("%lld",array[i]);
        }
        else
        {
            printf("%lld ",array[i]);
        }
    }
    return 0;
}
//123456789012 1234567890123