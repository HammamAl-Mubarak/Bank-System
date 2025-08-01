#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsListUsersScreen:protected clsScreen
{

private :

    static void _PrintUserRecordLine(clsUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;

    }

public:

    static void ShowUsersList()
    {
        vector<clsUser>vUsers = clsUser::GetUsersList();

        string Title = "\t  Users List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") Users(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout <<   "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout <<   "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;


        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else
        {
            for (clsUser User : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }
        }

        cout <<   "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};

