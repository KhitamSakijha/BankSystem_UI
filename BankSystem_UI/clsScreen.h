#pragma once
//#pragma warning(disable : 4996)
#include <iostream>
#include<ctime>
#include"Global.h"
#include"clsDate.h"
#include"clsUser.h"
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
        cout << "\t\t\t\t\t User : " << CurrentUser.UserName << endl;
        cout << "\t\t\t\t\t Date : " << clsDate::DateToString(clsDate())<<"\n\n";
       
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission) {
        if (!CurrentUser.CheckAccessPermission(Permission)) {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied ! Contact Your Admin\n";
            cout << "\t\t\t\t\t______________________________________\n";
            return false;
        }
        else
        {
            return true;
        }
    }

};

