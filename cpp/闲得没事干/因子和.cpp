#include<stdio.h>
#include<time.h>
// int Sum_Yinzi(int number)
// {
//     int result=0;
//     for (int i = 1; i < number; i++)
//     {
//         if(number%i==0)
//         {
//             result+=i;
//         }
//     }
//     return result;  
// }
int main()
{
    clock_t start,end;
    start=clock();
    int range=3000;
    for(int i=1;i<=range;i++)
    {
        int sum_i=0;
        //求i的因子和
        for (int k = 1; k < i; k++)
        {
            if(i%k==0)
            {
                sum_i+=k;
            }
        }
        for(int j=i+1;j<=range;j++)
        {
            int sum_j=0;
            //求j的因子和
            for (int k = 1; k < j; k++)
            {
                if(j%k==0)
                {
                    sum_j+=k;
                }
            }
            //判断因子和是否相等
            if(sum_j==i&&sum_i==j)
            {
                printf("%d,%d\n",i,j);              
            }
        }
    }
    end=clock();
    printf("\n\nRunning Time: %f m\n", ((double)(end-start))/CLOCKS_PER_SEC);
    return 0;
}