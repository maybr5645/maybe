// 公司为三类：普通员工、经理、老板，显示信息时，需要显示职工编号，职工姓名，职工岗位，职责 
// 普通员工职责：完成经理交给的任务
// 经理职责：完成老板交给的任务，并下发任务给员工
// 老板职责：管理公司所有事务
// 管理系统中需要实现的功能如下：
// 1.退出管理程序：退出当前管理系统
// 2.增加工信息：实现批量添加职工功能，将信息录入到文件中，职工信息为：职工编号，姓名，部门编号
// 3.显示信息：显示公司内部所有职工的信息
// 4.删除离职职工：按照编号删除指定的职工
// 5.修改职工信息：按照编号修改职工个人信息
// 6.查找职工信息：按照职工的编号或者职工的姓名进行查找相关的人员信息
// 7.按照编号排序：按照职工编号，进行排序，排序规则由用户指定
// 8.清空所有文档：清空文件中记录的所有职工信息（清空前需要再次确认，防止误删）
#include <iostream>
#include <workManager.h>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include <boss.h>
//**************************
int main()
{
    while(true)
    {
        WorkerManager wm;
        wm.Show_Menu();
        int function_select_number=0;
        cout<<"---请输入功能选择编号：---"<<endl;
        cin>>function_select_number;
        switch (function_select_number)
        {
            case 0://退出系统
                wm.Exit_System();
                break;
            case 1://增加
                cout<<"当前功能为：增加职工"<<endl;
                wm.Add_Worker();
                break;
            case 2://显示
                wm.Show_Worker();
                break;
            case 3://删除
                wm.Delete_Worker();
                break;
            case 4://修改
                // wm.Modify_Worker();
                break;
            case 5://查找
                wm.Find_Worker();
                break;
            case 6://排序
                wm.Sort_Worker();
                break;
            case 7://清空
                wm.Clear_Worker();
                break;
            default:
                cout<<"---输入有误,请重新输入---"<<endl;
                system("clear");
                break;
        }
    }
    return 0;
}