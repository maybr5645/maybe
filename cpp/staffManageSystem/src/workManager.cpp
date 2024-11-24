//菜单界面
//增删查改操作
//文件的读写
#include "workManager.h"
WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件不存在"<<endl;
        this->worker_number=0;
        this->is_File_Empty=true;
        this->worker_array=nullptr;
        ifs.close();
        return;
    }
    //文件存在但没有内容，被用户清除
    char ch;
    //如果文件为空，读取的是文件的结尾标志
    ifs>>ch;
    if(ifs.eof()) 
    {
        cout<<"文件为空！"<<endl;
        this->worker_number=0;
        this->worker_array=nullptr;
        this->is_File_Empty=true;
        ifs.close();
        return;
    }
    //文件存在且内容不为空
    int worker_number=Get_Worker_Number();
    this->is_File_Empty=false;
    // cout<<"当前共有"<<worker_number<<"名职工"<<endl;
    this->worker_number=worker_number;
    this->worker_array=new Worker*[this->worker_number];
    this->init_worker();
}

WorkerManager::~WorkerManager()
{
    if(this->worker_array!=nullptr)
    {
        for(int i=0;i<this->worker_number;i++)
        {
            if(this->worker_array[i]!=nullptr)
            {
                delete this->worker_array[i];
            }
        }
    }
    delete[] this->worker_array;
    this->worker_array=nullptr;
}

void WorkerManager::Show_Menu()
{
    cout<<"***************************"<<endl;
    cout<<"***欢迎使用职工管理系统!***"<<endl;
    cout<<"******0.退出管理程序*******"<<endl;
    cout<<"******1.增加职工信息*******"<<endl;
    cout<<"******2.显示职工信息*******"<<endl;
    cout<<"******3.删除离职员工*******"<<endl;
    cout<<"******4.修改职工信息*******"<<endl;
    cout<<"******5.查找职工信息*******"<<endl;
    cout<<"******6.按照编号排序*******"<<endl;
    cout<<"******7.清空所有文档*******"<<endl;
    cout<<"***************************"<<endl;
    cout<<endl;
}
void WorkerManager::Add_Worker()
{
    int add_number=0;
    cout<<"---请输入要添加职工的数量：---"<<endl;
    cin>>add_number;
    if(add_number>0)
    {
        //重新计算空间大小,原来的人数加上新加的人数
        int new_size=this->worker_number+add_number;
        //开辟新空间       
        Worker ** new_space=new Worker*[new_size];
        //将原数据拷贝到新空间
        if(this->worker_array!=nullptr)
        {
            for(int i=0;i<this->worker_number;i++)
            {
                new_space[i]=this->worker_array[i];
            } 
        }
        //批量添加新数据
        for(int i=0;i<add_number;i++)
        {
            int id;
            string name;
            int depart_id;
            cout<<"---请输入第"<<i+1<<"个新职工的编号:---"<<endl;
            cin>>id;
            cout<<"---请输入第"<<i+1<<"个新职工的名字:---"<<endl;
            cin>>name;
            cout<<"---请输入第"<<i+1<<"个新职工的部门编号:---"<<endl;
            cout<<"---1.普通职工"<<endl;
            cout<<"---2.经理"<<endl;
            cout<<"---3.老板"<<endl;
            cin>>depart_id;
            Worker *worker=nullptr;
            switch (depart_id)
            {
            case 1:
                worker=new Employee(id,name,1);
                break;
            case 2:
                worker=new Manager(id,name,2);
                break;
            case 3:
                worker=new Boss(id,name,3);
                break;
            default:
                break;
            }
            //将新职工保存在数组中
            new_space[this->worker_number+i]=worker;
            // Save();
        }
        //释放原有空间
        delete[] this->worker_array;
        // 更改新空间的指向
        this->worker_array=new_space;
        //更新职工人数
        this->worker_number=new_size;
        Save();
        cout<<"---已成功添加"<<add_number<<"名新职工---"<<endl;
        // cout<<this->worker_number<<endl;
        My_Pause();
        system("clear");
    }
    else
    {
        cout<<"---输入有误,请重新输入---"<<endl;
    }
}
void WorkerManager::Show_Worker()
{
    if(this->is_File_Empty)
    {
        cout<<"文件不存在或为空"<<endl;
    }
    else
    {
        for(int i=0;i<this->worker_number;i++)
        {
            this->worker_array[i]->show_info();
        }
    }
    My_Pause();
    system("clear");
}
void WorkerManager::My_Pause()
{
    cout << "按Enter键继续......"<<endl;
    system("read");
}
void WorkerManager::Exit_System()
{
    cout<<"---已退出系统，欢迎下次使用---"<<endl;
    My_Pause();
}
void WorkerManager::Save()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    for(int i=0;i<this->worker_number;i++)
    {
        ofs<<this->worker_array[i]->id<<" "
        <<this->worker_array[i]->name<<" "
        <<this->worker_array[i]->depart_id<<endl;

    }        
    ofs.close();
}
int WorkerManager::Get_Worker_Number()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int depart_id;
    int worker_number=0;
    while(ifs>>id&&ifs>>name&&ifs>>depart_id)
    {
        worker_number++;
    }
    return worker_number;
}
void WorkerManager::init_worker()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int depart_id;
    int index=0;
    while(ifs>>id&&ifs>>name&&ifs>>depart_id)
    {
        Worker* worker=nullptr;
        if(depart_id==1)
        {
            worker=new Employee(id,name,1);
        }
        else if(depart_id==2)
        {
            worker=new Manager(id,name,2);
        }
        else
        {
            worker=new Boss(id,name,3);
        }
        this->worker_array[index]=worker;
        index++;
    }
    ifs.close();
}
void WorkerManager::Delete_Worker()
{
    if(this->is_File_Empty)
    {
        cout<<"文件不存在或记录为空"<<endl;
    }
    else
    {
        int delete_id;
        cout<<"---请输入想要删除职工的编号：---"<<endl;
        cin>>delete_id;
        int delete_index=this->Find_Worker_Id(delete_id);
        // delete this->worker_array[Delete_Index];
        if(delete_id==-1)
        {
            cout<<"---未找到该职工---"<<endl;
        }
        else
        {
            cout<<"---该职工存在,将进行删除操作---"<<endl;
            for(int i=delete_index;i<this->worker_number-1;i++)
            {
                this->worker_array[i]=this->worker_array[i+1];
            }
            cout<<"---删除成功---"<<endl;
            this->worker_number--;
            this->Save();
        }
    }
    this->My_Pause();
    system("clear");
}
int WorkerManager::Find_Worker_Id(int id)
{
    int index=-1;
    for (int i = 0; i < this->worker_number; i++)
    {
        if(this->worker_array[i]->id==id)
        {
            index=i;
            break;
        }
    } 
    return index;
}
int WorkerManager::Find_Worker_Name(string name)
{
    int index=-1;
    for (int i = 0; i < this->worker_number; i++)
    {
        if(this->worker_array[i]->name==name)
        {
            index=i;
            break;
        }
    } 
    return index;
}

void WorkerManager::Modify_Worker()
{
    if(this->is_File_Empty)
    {
        cout<<"文件不存在或记录为空"<<endl;
    }
    else
    {
        int modify_id;
        cout<<"请输入想要修改的职工的编号："<<endl;
        cin>>modify_id;
        int modify_index=this->Find_Worker_Id(modify_id);
        if(modify_index!=-1)
        {
            // delete this->worker_array[modify_index];
            // this->worker_array[modify_index]=nullptr;
            int new_id;
            string new_name;
            int new_depart_id;
            cout<<"请输入修改后的编号:"<<endl;
            cin>>new_id;
            cout<<"请输入修改后的姓名:"<<endl;
            cin>>new_name;
            cout<<"请输入修改后的岗位:"<<endl;
            cin>>new_depart_id;
            Worker *worker=nullptr;
            switch (new_depart_id)
            {
                case 1:
                    worker=new Employee(new_id,new_name,new_depart_id);
                    break;
                case 2:
                    worker=new Manager(new_id,new_name,new_depart_id);
                    break;
                case 3:
                    worker=new Boss(new_id,new_name,new_depart_id);
                    break;
                default:
                    break;
            }
            this->worker_array[modify_index]=worker;
        }
        else
        {
            cout<<"未找到该员工"<<endl;

        }
    }
    this->My_Pause();
    system("clear");
}
void WorkerManager::Find_Worker()
{
    cout<<"请选择查找的方式："<<endl;
    cout<<"1.编号"<<endl;
    cout<<"2.姓名"<<endl;
    int Find_Way_Number;
    cin>>Find_Way_Number;
    if(Find_Way_Number==1)
    {
        cout<<"---请输入查找的编号:---"<<endl;
        int find_id;
        cin>>find_id;
        int find_index=this->Find_Worker_Id(find_id);
        if(find_index!=-1)
        {
            cout<<"---成功找到!---"<<endl;
            this->worker_array[find_index]->show_info();
        }
        else
        {
            cout<<"---未找到此人---"<<endl;
        }
    }
    else
    {
        cout<<"---请输入查找的姓名:---"<<endl;
        string find_name;
        cin>>find_name;
        int find_index=this->Find_Worker_Name(find_name);
        if(find_index!=-1)
        {
            cout<<"---成功找到!---"<<endl;
            this->worker_array[find_index]->show_info();
        }
        else
        {
            cout<<"---未找到此人---"<<endl;
        }
    }
    this->My_Pause();
    system("clear");
}
void WorkerManager::Sort_Worker()
{
    int sort_way_number;
    cout<<"请选择排序的方式:"<<endl;
    cout<<"方式1.按照编号从小到大,请输入数字 1"<<endl;
    cout<<"方式2.按照编号从大到小,请输入数字 2"<<endl;
    cin>>sort_way_number;
    if(sort_way_number==2)
    {
        for (int i = 0; i < this->worker_number-1; i++)
        {
            int max=i;
            for (int j = i; j < this->worker_number; j++)
            {
                if(this->worker_array[max]->id<this->worker_array[j]->id)
                {
                    max=j;
                }
            }
            if(max!=i)
            {
                Worker* temp=nullptr;
                temp=this->worker_array[max];
                this->worker_array[max]=this->worker_array[i];
                this->worker_array[i]=temp;
            }  
        }
        
    }
    else
    {
        for (int i = 0; i < this->worker_number-1; i++)
        {
            int min=i;
            for (int j = i; j < this->worker_number; j++)
            {
                if(this->worker_array[min]->id>this->worker_array[j]->id)
                {
                    min=j;
                }
            }
            if(min!=i)
            {
                Worker* temp=nullptr;
                temp=this->worker_array[min];
                this->worker_array[min]=this->worker_array[i];
                this->worker_array[i]=temp;
            }  
        }
    }
    this->Save();
    this->Show_Worker();
    this->My_Pause();
    system("clear");
}
void WorkerManager::Clear_Worker()
{
    cout<<"---是否确定清除所有信息?---"<<endl;
    cout<<"---确定:输入数字 1"<<endl;
    cout<<"---取消:输入数字 0"<<endl;
    int clear_confirm_number;
    cin>>clear_confirm_number;
    if(clear_confirm_number)
    {
        ofstream ofs;
        ofs.open(FILENAME,ios::trunc);
        ofs.close();
        if(this->worker_array!=nullptr)
        {
            for(int i=0;i<this->worker_number;i++)
            {
                delete this->worker_array[i];
                this->worker_array[i]=nullptr;
            }
        }
        delete[] this->worker_array;
        this->worker_number=0;
        this->worker_array=nullptr;
        this->is_File_Empty=true;
        cout<<"---已成功清除所有信息---"<<endl;
    }
    else
    {
        cout<<"已取消清除操作"<<endl;
    }
    this->My_Pause();
    system("clear");
}