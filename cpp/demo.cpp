#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <algorithm>
using namespace std;
//**************************
//查找内置的数据类型
class Greater_Five
{
public:
    bool operator()(int val)
    {
        return val>5;
    }
};
void func1()
{
    vector <int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it=find_if(v.begin(),v.end(),Greater_Five());
    if(it==v.end())
    {
        cout<<"nonono"<<endl;
    }
    else
    {
        cout<<"yes"<<*it<<endl;
    }
}
// 查找自定义的数据类型

class Person
{
public:
    Person(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
    //重载操作符
    bool operator==( Person& p)
    {
        if(this->name==p.name&&this->age==p.age)
        {
            return true;
        }
        return false;
    }
    string name;
    int age;
};
class Greater_Age
{
public:
    bool operator()(Person& p)
    {
        return p.age>15;
    }
};
void func2()
{
    vector<Person> v;
    Person p1("a",10);
    Person p2("b",20);
    v.push_back(p1);
    v.push_back(p2);
    vector<Person>::iterator it=find_if(v.begin(),v.end(),Greater_Age());
    if(it==v.end())
    {
        cout<<"nonono"<<endl;
    }
    else
    {
        cout<<"yes"<<"\t"<<it->name<<endl;
    }
}
int main()
{
    func2();
    return 0;
}