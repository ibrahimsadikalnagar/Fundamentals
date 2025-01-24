#pragma once
#include <iostream>
#include"clsUser.h"
#include"Global.h"
#include"clsDate.h"

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\tUser : " << CurrentUser.UserName << endl; 
        cout << "\t\t\t\t\tTime : " << clsDate::DateToString(clsDate())<<"\n\n" << endl;
    }
    
    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t_______________________________________"; 
            cout << "\n\n\t\t\t\t Access Denied ! Contact your admin" << endl; 
            cout << "\t\t\t\t_______________________________________"; 
            return false; 
        }
        else
        {
            return true; 
        }
    }

};

