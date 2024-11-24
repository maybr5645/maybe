#include <iostream>
using namespace std;
bool find_substr(string &str,string &sub_str);
int main()
{
    string str;
    cout<<"请输入字符串:";
    cin>>str;
    string sub_str;
    cout<<"请输入子字符串:";
    cin>>sub_str;   
    if(find_substr(str,sub_str))
    {
        cout<<"yesyesyes!!"<<endl;
    }
    else
    {
        cout<<"nonono~~~"<<endl;
    }
    return 0;
}
bool find_substr(string &str,string &sub_str)
{
    int len_str=str.size();
    int len_sub_str=sub_str.size();
    for(int i=0;i<=len_str-len_sub_str;i++)
    {
        if(str[i]==sub_str[0])
        {
            int count=0;
            for(int j=0;j<len_sub_str;j++)
            {
                if(sub_str[j]==str[i+j])
                {
                    count++;
                }
            }
            if(count==len_sub_str)
            {
                return true;
            }
        }  
    }
    return false;
}
