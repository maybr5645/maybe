#include <stdio.h>
int func();
int main()
{
    printf("%d",func());
    return 0;
}
int func()
{
    int n;//n<=30
    double up=2;
    double low=1;
    double result=0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        result+=up/low;
        int temp=up;
        up+=low;
        low=temp;
    }
    return (int)result;
}
