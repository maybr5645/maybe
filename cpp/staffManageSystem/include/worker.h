#pragma once
#include <iostream>
using namespace std;
//**************************
class Worker
{
public:
    virtual void show_info()=0;
    virtual string get_depart_name()=0;
    virtual ~Worker()=0;
    int id;
    string name;
    int depart_id;
};
