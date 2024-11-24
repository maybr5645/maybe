#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
class Manager:public Worker
{
public:
    Manager(int id,string name,int depart_id);
    ~Manager();
    virtual void show_info();
    virtual string get_depart_name();
};