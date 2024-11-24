/*
系统中需要实现的功能如下:
***添加联系人: 向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
***显示联系人: 显示通讯录中所有联系人信息
***删除联系人: 按照姓名进行删除指定联系人
***查找联系人: 按照姓名查看指定联系人信息
***修改联系人: 按照姓名重新修改指定联系人
***清空联系人: 清空通讯录中所有信息
***退出通讯录: 退出当前使用的通讯录
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define PERSON_MAX 1000
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
struct Person
{
    string name;
    int sex;
    int age;
    string phone_number;
    string address;
};
struct System
{
    struct Person arr_contact_person[PERSON_MAX];
    int person_number = 0;
};
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
string Sex_Transform(int sex);
void Show_Menu();
void Add_Contact(struct System *contact_system);
void Show_Contact(struct System *contact_system);
void Delete_Contact(struct System *contact_system);
void Find_Contact(struct System *contact_system);
void Modify_Contact(struct System *contact_system);
void Clear_Contact(struct System *contact_system);
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    system("chcp 65001"); // 正常显示中文
    using namespace std;
    System contact_system;
    // int person_number=sizeof(contact_system.arr_contact_person)/sizeof(contact_system.arr_contact_person[0]);
    int function_select_number = 0;
    while (true)
    {
        Show_Menu();                                    // 展示菜单界面
        cout << "---请输入选择的功能代码: ---" << endl; // 读入选择的代码，判断功能
        cin >> function_select_number;
        switch (function_select_number)
        {
        case 0:
            cout << "---已退出系统，欢迎下次使用---" << endl;
            exit(0); // 直接退出系统
            break;
        case 1:
            cout << "---当前功能: 1.添加联系人---" << endl;
            Add_Contact(&contact_system);
            break;
        case 2:
            cout << "---当前功能: 2.显示联系人---" << endl;
            Show_Contact(&contact_system);
            break;
        case 3:
            cout << "---当前功能: 3.删除联系人---" << endl;
            Delete_Contact(&contact_system);
            break;
        case 4:
            cout << "---当前功能: 4.查找联系人---" << endl;
            Find_Contact(&contact_system);
            break;
        case 5:
            cout << "---当前功能: 5.修改联系人---" << endl;
            Modify_Contact(&contact_system);
            break;
        case 6:
            cout << "---当前功能: 6.清空联系人---" << endl;
            Clear_Contact(&contact_system);
            break;
        }
    }
    return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------
string Sex_Transform(int sex)
{
    string string_sex;
    if (sex)
    {
        string_sex = "男";
    }
    else
    {
        string_sex = "女";
    }

    return string_sex;
}
void Show_Menu()
{
    cout << "************************************" << endl;
    cout << "**********  1.添加联系人  **********" << endl;
    cout << "**********  2.显示联系人  **********" << endl;
    cout << "**********  3.删除联系人  **********" << endl;
    cout << "**********  4.查找联系人  **********" << endl;
    cout << "**********  5.修改联系人  **********" << endl;
    cout << "**********  6.清空联系人  **********" << endl;
    cout << "**********  0.退出通讯录  **********" << endl;
    cout << "************************************" << endl;
}
void Add_Contact(struct System *contact_system)
{
    // 判断人数是否大于最大值
    if (contact_system->person_number == PERSON_MAX)
    {
        cout << "---通讯录人数已满,无法继续添加---" << endl;
        return;
    }
    else
    {
        // 姓名
        cout << "---请输入添加人的姓名: ---" << endl;
        cin >> contact_system->arr_contact_person[contact_system->person_number].name;
        // 性别
        cout << "---请输入添加人的性别(女0男1): ---" << endl;
        cin >> contact_system->arr_contact_person[contact_system->person_number].sex;
        // 年龄
        cout << "---请输入添加人的年龄: ---" << endl;
        cin >> contact_system->arr_contact_person[contact_system->person_number].age;
        // 电话
        cout << "---请输入添加人的电话号: ---" << endl;
        cin >> contact_system->arr_contact_person[contact_system->person_number].phone_number;
        // 住址
        cout << "---请输入添加人的住址: ---" << endl;
        cin >> contact_system->arr_contact_person[contact_system->person_number].address;
        // 更新通讯录人数
        contact_system->person_number++;
        cout << "---联系人添加完成,当前通讯录总人数 " << contact_system->person_number << "/1000---" << endl;
        system("pause");
        system("cls");
    }
}
void Show_Contact(struct System *contact_system)
{
    if (contact_system->person_number == 0)
    {
        cout << "---目前无联系人---" << endl;
    }
    else
    {
        for (int i = 0; i < contact_system->person_number; i++)
        {
            cout << "序号" << i + 1 << "\t  姓名:" << contact_system->arr_contact_person[i].name << "\t  性别:" << Sex_Transform(contact_system->arr_contact_person[i].sex) << "\t  年龄:" << contact_system->arr_contact_person[i].age << "\t  电话:" << contact_system->arr_contact_person[i].phone_number << "\t  住址:" << contact_system->arr_contact_person[i].address << endl;
        }
    }
    system("pause");
    system("cls");
}
void Delete_Contact(struct System *contact_system)
{
    string delete_contact_name;
    int same_name_number = 0;
    int delete_contact_number = 0;
    int delete_confirm_number = 0;
    cout << "---请输入要删除的联系人的姓名：---" << endl;
    cin >> delete_contact_name;
    for (int i = 0; i < contact_system->person_number; i++)
    {
        if (contact_system->arr_contact_person[i].name == delete_contact_name)
        {
            delete_contact_number = i + 1;
            cout << "序号" << i + 1 << "\t  姓名:" << contact_system->arr_contact_person[i].name << "\t  性别:" << Sex_Transform(contact_system->arr_contact_person[i].sex) << "\t  年龄:" << contact_system->arr_contact_person[i].age << "\t  电话:" << contact_system->arr_contact_person[i].phone_number << "\t  住址:" << contact_system->arr_contact_person[i].address << endl;
            same_name_number++;
        }
    }
    // cout << "共找到" << same_name_number << "人" << endl;
    if (same_name_number == 0)
    {
        cout << "---未找到此联系人---" << endl;
    }
    else if (same_name_number == 1)
    {
        cout << "---共找到" << same_name_number << "人---" << endl;
        cout << "---是否确定删除此联系人?(同意按1/拒绝按0)---" << endl;
        cin >> delete_confirm_number;
        if (delete_confirm_number)
        {
            for (int i = delete_contact_number - 1; i < contact_system->person_number; i++)
            {
                contact_system->arr_contact_person[i] = contact_system->arr_contact_person[i + 1];
            }
            contact_system->person_number--;
        }
        else
        {
            system("pause");
            system("cls");
        }
    }
    else if (same_name_number > 1)
    {
        int delete_select_number;
        cout << "---找到" << same_name_number << "个同名的联系人，请输入需要删除的联系人的序号:---" << endl;
        cin >> delete_select_number;
        for (int i = 0; i < contact_system->person_number; i++)
        {
            if (i == delete_select_number)
            {
                // struct Person arr_contact_person_null[1];
                for (int j = 0; j < i; j++)
                {
                    contact_system->arr_contact_person[j] = contact_system->arr_contact_person[j + 1];
                }
            }
        }
        contact_system->person_number--;
    }
    cout << "---删除操作已完成---" << endl;
    system("pause");
    system("cls");
}
void Find_Contact(struct System *contact_system)
{
    string find_contact_name;
    int same_name_number = 0;
    cout << "---请输入要查找的联系人的姓名：--- "<< endl;
    cin >> find_contact_name;
    for (int i = 0; i < contact_system->person_number; i++)
    {
        if (contact_system->arr_contact_person[i].name == find_contact_name)
        {
            cout << "序号" << i + 1 << "\t  姓名:" << contact_system->arr_contact_person[i].name << "\t  性别:" << Sex_Transform(contact_system->arr_contact_person[i].sex) << "\t  年龄:" << contact_system->arr_contact_person[i].age << "\t  电话:" << contact_system->arr_contact_person[i].phone_number << "\t  住址:" << contact_system->arr_contact_person[i].address << endl;
            same_name_number++;
        }
    }
    cout << "---共找到" << same_name_number << "人---" << endl;
    system("pause");
    system("cls");
}
void Modify_Contact(struct System *contact_system)
{
    string modify_contact_name;
    int same_name_number = 0;
    int modify_contact_number = 0;
    int modify_confirm_number = 0;
    cout << "---请输入要修改信息的联系人的姓名：---" << endl;
    cin >> modify_contact_name;
    for (int i = 0; i < contact_system->person_number; i++)
    {
        if (contact_system->arr_contact_person[i].name == modify_contact_name)
        {
            modify_contact_number = i + 1;
            cout << "序号" << i + 1 << "\t  姓名:" << contact_system->arr_contact_person[i].name << "\t  性别:" << Sex_Transform(contact_system->arr_contact_person[i].sex) << "\t  年龄:" << contact_system->arr_contact_person[i].age << "\t  电话:" << contact_system->arr_contact_person[i].phone_number << "\t  住址:" << contact_system->arr_contact_person[i].address << endl;
            same_name_number++;
        }
    }
    // cout << "共找到" << same_name_number << "人" << endl;
    if (same_name_number == 0)
    {
        cout << "---未找到此联系人---" << endl;
    }
    else if (same_name_number == 1)
    {
        cout << "---共找到" << same_name_number << "人---" << endl;
        cout << "---是否确定修改此联系人的信息?(同意按1/拒绝按0)---" << endl;
        cin >> modify_confirm_number;
        if (modify_confirm_number)
        {
            // 姓名
            cout << "---请输入修改后联系人的姓名: ---" << endl;
            cin >> contact_system->arr_contact_person[modify_contact_number - 1].name;
            // 性别
            cout << "---请输入修改后联系人的性别(女0男1): ---" << endl;
            cin >> contact_system->arr_contact_person[modify_contact_number - 1].sex;
            // 年龄
            cout << "---请输入修改后联系人的年龄: ---" << endl;
            cin >> contact_system->arr_contact_person[modify_contact_number - 1].age;
            // 电话
            cout << "---请输入修改后联系人的电话号: ---" << endl;
            cin >> contact_system->arr_contact_person[modify_contact_number - 1].phone_number;
            // 住址
            cout << "---请输入修改后联系人的住址: ---" << endl;
            cin >> contact_system->arr_contact_person[modify_contact_number - 1].address;

            cout << "---此联系人信息修改完成---" << endl;
        }
        else
        {
            system("pause");
            system("cls");
        }
    }
    else if (same_name_number > 1)
    {
        int modify_select_number;
        cout << "---找到" << same_name_number << "个同名的联系人，请输入需要删除的联系人的序号:---" << endl;
        cin >> modify_select_number;
        for (int i = 0; i < contact_system->person_number; i++)
        {
            if (i == modify_select_number)
            {
                // 姓名
                cout << "---请输入修改后联系人的姓名: ---" << endl;
                cin >> contact_system->arr_contact_person[modify_select_number - 1].name;
                // 性别
                cout << "---请输入修改后联系人的性别(女0男1): ---" << endl;
                cin >> contact_system->arr_contact_person[modify_select_number - 1].sex;
                // 年龄
                cout << "---请输入修改后联系人的年龄: ---" << endl;
                cin >> contact_system->arr_contact_person[modify_select_number - 1].age;
                // 电话
                cout << "---请输入修改后联系人的电话号: ---" << endl;
                cin >> contact_system->arr_contact_person[modify_select_number - 1].phone_number;
                // 住址
                cout << "---请输入修改后联系人的住址: ---" << endl;
                cin >> contact_system->arr_contact_person[modify_select_number - 1].address;

                cout << "---此联系人信息修改完成---" << endl;
                system("pause");
                system("cls");
            }
        }
    }
    system("pause");
    system("cls");
}
void Clear_Contact(struct System *contact_system)
{
    int clear_confirm_number = 0;
    cout << "---是否确定清空通讯录?(同意按1/拒绝按0)---" << endl;
    cin >> clear_confirm_number;

    if (clear_confirm_number)
    {
        struct System system_null;
        *contact_system = system_null;
        cout << "---已完成清空操作---" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "---已取消清空操作---" << endl;
        system("pause");
        system("cls");
    }
}
