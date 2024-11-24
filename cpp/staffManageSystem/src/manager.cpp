#include "manager.h"

Manager::Manager(int id,string name,int depart_id)
{
    this->id=id;
    this->name=name;
    this->depart_id=depart_id;
}
Manager::~Manager()
{

}
void Manager::show_info()
{
    cout<<"职工编号: "<<this->id
    <<"\t职工姓名: "<<this->name
    <<"\t岗位: "<<this->get_depart_name()
    <<"\t岗位职责: 完成老板交给的任务,并下发给员工"<<endl;
}

string Manager::get_depart_name()
{
    return string("经理");
}