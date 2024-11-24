#include <iostream>
using namespace std;
void rev_str(string str,int len)
{
    for (int i = len-1; i >=0; i++)
    {
        cout<<str[i]<<" ";
    }
}
int main()
{
    string str;
    cin>>str;
    int len=str.size();
    rev_str(str,len);
    return 0;
}