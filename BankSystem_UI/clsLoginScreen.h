#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include"Global.h"
#include"clsMainScreen.h"
#include"clsUtil.h"
class clsLoginScreen :protected clsScreen
{
private:

	static bool _Login() {
		bool LoginFaild = false;
		short FaildLoginCount = 0;
		string UserName,PassWerd;
		
		do
		{
				if (LoginFaild) {
					FaildLoginCount++;
					cout << "\nInvlaid User Name /Pass Word";
					cout << "\nYou have " << (3 - FaildLoginCount) << "Trial(s) to login.\n\n";
				}

				if (FaildLoginCount == 3) {
					system("cls");
					cout << "\n\n\t\t\t\tYour are locked after 3 faild trails\n\n";
					return false;
				}

				cout << "Enter User Name :";
				cin >> UserName;
				cout << "Enter Pass Word : ";
				cin >> PassWerd;
				CurrentUser = clsUser::Find(UserName,PassWerd);
				LoginFaild = CurrentUser.IsEmpty();
			
		} while (LoginFaild);
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:
	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t    Login Screen");
		return _Login();
	}
};

