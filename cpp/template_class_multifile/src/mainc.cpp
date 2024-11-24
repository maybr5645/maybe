#include <iostream>
using namespace std;
#include "person.hpp"

void test01()
{
    Person<string,int>p1("tom",18);
    p1.Show_Info();
}
int main()
{
    test01();
    return 0;
}