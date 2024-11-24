#pragma once
#include <iostream>
#include <fstream>
#define FILENAME "worker_file.txt"
using namespace std;
#include "worker.h"
#include "employee.h"   
#include "manager.h"
#include "boss.h"
//**************************
class WorkerManager
{
public:
    WorkerManager();
    virtual ~WorkerManager();
    void Show_Menu();
    void Exit_System();
    void My_Pause();
    void Add_Worker();
    void Show_Worker();
    bool is_File_Empty;
    int Get_Worker_Number();
    void init_worker();
    void Delete_Worker();
    int Find_Worker_Id(int id);
    int Find_Worker_Name(string name);
    void Modify_Worker();
    void Find_Worker();
    void Sort_Worker();
    void Clear_Worker();
    void Save();
    int worker_number;
    Worker** worker_array;
};