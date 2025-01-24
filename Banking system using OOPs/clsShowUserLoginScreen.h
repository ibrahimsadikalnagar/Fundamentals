#pragma once
class clsShowUserLoginScreen:protected clsScreen
{
private:
	static void PrintClientRecordLine(clsUser::stLoginRegstorRecord1 LoginRegistor)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegistor.DateTime;
			cout << "| " << setw(20) << left << LoginRegistor.UserName;
		cout << "| " << setw(20) << left << LoginRegistor.Password;
		cout << "| " << setw(1) << left << LoginRegistor.Permission;
		
	}
public: 
	static void ShowUserLoginList()
	{
		if (!CheckAccessRights(clsUser::enPermissions::epLoginListUser))
		{
			return; 
		}
		vector<clsUser::stLoginRegstorRecord1> vReg = clsUser::GetLoginRegisterList(); 
		string Title = "\t User Login List "; 
		string Subtitle = " \t     ( " + to_string(vReg.size()) + ") Client(s). "; 
		_DrawScreenHeader(Title, Subtitle); 
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n"
			<< endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		
		cout << "| " << left << setw(20) << "Username";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permission";
		
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n"
			<< endl;



		if (vReg.size() == 0)
			cout << "\t\t\t\tNo Logins Available In the System!";
		else

			for (clsUser::stLoginRegstorRecord1 Record : vReg)
			{

				PrintClientRecordLine(Record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n"
			<< endl;
	}

};

