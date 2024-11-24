#include "speechManager.h"
SpeechManager::SpeechManager()
{
    this->Init();
    this->Creat_Speaker();
}
SpeechManager::~SpeechManager()
{

}
void SpeechManager::My_Pause()
{
    cout << "\n按Enter键继续......"<<endl;
    system("read");
}
void SpeechManager::Init()
{
    this->v1.clear();
    this->v2.clear();
    this->v_victory.clear();
    this->map_speaker.clear();
    this->index=1;
}
void SpeechManager::Show_Menu()
{
    // system("clear");
    cout<<"************************"<<endl;
    cout<<"*** 欢迎参加演讲比赛!***"<<endl;
    cout<<"**** 1.开始演讲比赛 ****"<<endl;
    cout<<"**** 2.查看往届记录 ****"<<endl;
    cout<<"**** 3.清空比赛记录 ****"<<endl;
    cout<<"**** 0.退出比赛程序 ****"<<endl;
    cout<<"************************"<<endl;
    cout<<endl;
}
void SpeechManager::Function_Select()
{
    cout<<"---请输入选择的功能序号:---"<<endl;
    int function_select_number;
    cin>>function_select_number;
    switch (function_select_number)
    {
    case 0:
        Exit_System();
        break;
    case 1:
        Start_Contest();
        break;
    case 2:
        Check_Previous_Record();
        break;
    case 3:
        Clear_Record();
        break;
    default:
        break;
    }
}
void SpeechManager::Exit_System()
{
    cout<<"---已退出系统---"<<endl;
    My_Pause();
    exit(0);
}
void SpeechManager::Creat_Speaker()
{
    string name_seed="ABCDEFGHIJKL";
    for (int i = 0; i < name_seed.size(); i++)
    {
        string name="选手";
        name+=name_seed[i];
        Speaker sp;
        sp.name=name;
        for(int i=0;i<2;i++)
        {
            sp.score[i]=0;
        }
        this->v1.push_back(i+10001);
        this->map_speaker.insert(make_pair(i+10001,sp));
    }
}
void SpeechManager::Draw_Speaker()
{
    cout<<"---第<<"<<this->index<<">>轮选手演讲顺序抽签如下---"<<endl;
    cout<<"-------------------------------------------"<<endl;
    // cout<<"---抽签结果如下:---"<<endl;
    if(this->index==1)
    {
        random_device rd;
        mt19937 g(rd());
        shuffle(v1.begin(),v1.end(),g);
        for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
        {
            cout<<*it<<"\t";
        }
    }
    else
    {
        random_device rd;
        mt19937 g(rd());
        shuffle(v2.begin(),v2.end(),g);
        for(vector<int>::iterator it=v2.begin();it!=v2.end();it++)
        {
            cout<<*it;
        }    
    }
    cout<<endl;
    cout<<"-------------------------------------------"<<endl;
    My_Pause();
}
void SpeechManager::Get_Score()
{
    cout<<"---第<<"<<this->index<<">>轮比赛结果如下---"<<endl;
    multimap<double,int,greater<double> > multimap_score;
    int num=0;
    vector<int> v_speaker;
    if(this->index)
    {
        v_speaker=v1;
    }
    else
    {
        v_speaker=v2;
    }
    
    for(vector<int>::iterator it=v_speaker.begin();it!=v_speaker.end();it++)
    {
        num++;
        deque<double> deque_score;
        for (int i = 0; i < 10; i++)
        {
            double score=(rand()%401+600)/10.f;
            // cout<<score<<" ";//test
            deque_score.push_back(score);
        }
        // cout<<endl;//test
        sort(deque_score.begin(),deque_score.end(),greater<double>());
        deque_score.pop_back();//去除最低分
        deque_score.pop_front();//去除最高分
        double sum=accumulate(deque_score.begin(),deque_score.end(),0.0f);
        double average=sum/(double)deque_score.size();
        // cout<<"编号:"<<*it<<"\t姓名"<<map_speaker[*it].name<<"\t分数"<<average<<endl;
        this->map_speaker[*it].score[this->index-1]=average;
        multimap_score.insert(make_pair(average,*it));
        if(num%6==0)
        {
            cout<<"第"<<num/6<<"小组比赛名次如下:"<<endl;
            for(multimap<double,int,greater<double> >::iterator it=multimap_score.begin();it!=multimap_score.end();it++)
            {
                cout<<"编号:"<<it->second<<"\t姓名:"<<this->map_speaker[it->second].name<<"\t分数:"<<it->first<<endl;
            }
            cout<<"--------------------------------------"<<endl;
            int count=0;
            for(multimap<double,int,greater<double> >::iterator it=multimap_score.begin();it!=multimap_score.end()&&count<3;it++,count++)
            {
                if(this->index==1)
                {
                    this->v2.push_back((*it).second);
                }
                else
                {
                    this->v_victory.push_back((*it).second);
                }
            }
            multimap_score.clear();
        }
    }
    cout<<"---第"<<this->index<<"轮比赛完毕！---"<<endl;
    My_Pause();
}
void SpeechManager::Show_Score()
{


}
void SpeechManager::Start_Contest()
{
    //第一轮比赛
    //抽签
    Draw_Speaker();
    //比赛,获得分数
    Get_Score();
}
void SpeechManager::Check_Previous_Record()
{

}
void SpeechManager::Clear_Record()
{

}

