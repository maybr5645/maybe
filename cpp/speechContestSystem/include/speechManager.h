#pragma onece
#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
#include <random>
#include <deque>
#include <functional>
#include "speaker.h"
#include <numeric>
using namespace std;
//**************************
class SpeechManager
{
public:
    SpeechManager();
    ~SpeechManager();
    void Init();//
    void Show_Menu();
    void My_Pause();
    void Exit_System();
    void Function_Select();
    void Start_Contest();
    void Creat_Speaker();
    void Draw_Speaker();
    void Get_Score();
    void Show_Score();
    void Check_Previous_Record();
    void Clear_Record();

    vector<int> v1;//第一轮选手，12 个
    vector<int> v2;//第二轮选手，6 个
    vector<int> v_victory;//第三轮选手，3 个
    map<int,Speaker> map_speaker;//存放编号和具体的选手
    int index;//记录轮数
};