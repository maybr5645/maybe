#include <stdio.h>
#include <stdlib.h>
int main()
{
    for(int i=1;i<=1000;i++)
    {
        // int* arr=(int*) malloc(sizeof(int)*5);
        // int size=5;//数组大小
        int arr[100];
        int count=0;//记录数组中的数量
        int sum=0;//因子和
        for(int j=1;j<i;j++)
        {
            if(i%j==0)
            {
                sum+=j;
                // if(count==size)
                // {
                //     size*=2;
                //     arr=(int*) realloc(arr,sizeof(int)*size);
                // }
                arr[count]=j;
                count++;
            }
        }
        if(sum==i)
        {
            printf("%d=",i);
            for (int i = 0; i < count; i++)
            {
                if(i==count-1)
                {
                    printf("%d\n",arr[i]);
                }
                else
                {
                    printf("%d+",arr[i]);
                }
            }
        }
    }
    return 0;
}