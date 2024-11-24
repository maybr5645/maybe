#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Employee:public Worker
{
public:
    Employee(int id,string name,int depart_id);
    ~Employee();
    virtual void show_info();
    virtual string get_depart_name();
};