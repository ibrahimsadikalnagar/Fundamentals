
#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "Global.h"


class clsLoginScreen :protected clsScreen
{

private:
    static void CountLogin()
    {

    }
    static  bool _Login()
    {
        bool LoginFaild = false;
        short counter = 1;
        string Username, Password;
        bool swtich = true;

        do
        {
            
            
               
                if (LoginFaild)
                {

                    cout << "\nInvlaid Username/Password!\n\n";
                    cout << "\nyou entered " << counter << " time";
                    cout << "\nonly you have :  " << 3 - counter;
                    counter++;
                }
               
                cout << "\n\nEnter Username? ";
                cin >> Username;
                cout << "\nEnter Password? ";
                cin >> Password;
                CurrentUser = clsUser::find(Username, Password);
                LoginFaild = CurrentUser.IsEmpty();
                if (counter == 3)
                {
                    cout << "the system is lock ";
                    exit(0);
     
                }
        } while (LoginFaild);
        CurrentUser.SaveRegisterLogin(); 

        clsMainScreen::ShowMainMenu(); 
    }

public:


    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        _Login();
        

    }

};


