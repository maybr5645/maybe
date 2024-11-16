#include <iostream>
using namespace std;
//**************************
bool is_Prime(int num)
{
    for(int i=2;i<num;i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;
}
bool is_Leapyear(int year)
{
    if(year%400==0||(year%4==0&&year%400!=0)||(year % 3200 == 0 && year % 172800 == 0))
    {
        return true;
    }
    return false;
}
bool is_Squarenumber(int number)
{
    for(int i=1;i<number;i++)
    {
        if(i*i==number)
        {
            return true;
        }
    }
    return false;
}
long long Factorial(int number)
{
    int result=0;
    for(int i=1;i<=number;i++)
    {
        int temp=1;
        for(int j=1;j<=i;j++)
        {
            temp*=j;
        }
        result+=temp;
    }
    return result;
}
int main()
{
    cout<<is_Prime(37)<<endl;
    cout<<is_Leapyear(2008)<<endl;
    cout<<is_Squarenumber(5)<<endl;
    cout<<Factorial(5)<<endl;
    return 0;
}