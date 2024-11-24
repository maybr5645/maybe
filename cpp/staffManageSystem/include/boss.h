#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
// #include <string>
class Boss:public Worker
{
public:
    Boss(int id,string name,int depart_id);
    ~Boss();
    virtual void show_info();
    virtual string get_depart_name();
};