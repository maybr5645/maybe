#include "boss.h"

Boss::Boss(int id,string name,int depart_id)
{
    this->id=id;
    this->name=name;
    this->depart_id=depart_id;
}
Boss::~Boss()
{

}
void Boss::show_info()
{
    cout<<"职工编号: "<<this->id
    <<"\t职工姓名: "<<this->name
    <<"\t岗位: "<<this->get_depart_name()
    <<"\t岗位职责: 下发任务给经理"<<endl;
}

string Boss::get_depart_name()
{
    return string("老板");
}