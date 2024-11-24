#include<iostream>
using namespace std;
bool is_sushu(int number)//判断一个数是否为素数
{
    if(number==0)
    {
        return false;
    }
    for (int i = 2; i < number; i++)
    {
        if(number%i==0)
        {
            return false;
        }
    }
    return true;
}
void test32(string str)
{
    int arr[26]={0};//使用一个数组存储 26个字母各自的出现次数
    int len=str.size();
    for(int i=0;i<len;i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            if(str[i]==j||str[i]==j+32)
            {
                arr[j-65]++;
            }       
        }
    }
    for(int i=0;i<26;i++)
    {
        if(is_sushu(arr[i]))
        {
            cout<<(char)(i+65)<<"/"<<(char)(i+97)<<"\t"<<arr[i]<<endl;
        } 
    }
}

int main()
{
    string str;
    cin>>str;
    test32(str);
    return 0;
}