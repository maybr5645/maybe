#include <iostream>
#include "speechManager.h"
using namespace std;
//**************************
int main()
{
    SpeechManager sm;
    // for(map<int,Speaker>::iterator it=sm.map_speaker.begin();it!=sm.map_speaker.end();it++)
    // {
    //     cout<<it->first<<" "<<it->second.name<<" "<<it->second.score[0]<<endl;
    // }
    while(1)
    {
        sm.Show_Menu();
        sm.Function_Select();
    }
    return 0;
}