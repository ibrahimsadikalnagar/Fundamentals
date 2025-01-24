#pragma once
#include<iostream>
#include"clsPerson.h"
#include<vector>
#include"clsString.h"
#include<string>
#include<string.h>
#include<fstream>
#include<iomanip>
#include"clsDate.h"
#include"clsString.h"
#include"clsUtil.h"
using namespace std; 

class clsUser:public clsPerson
{
private :
	

	enum enMode {enUpdateMode =1  , enEmptyMode =2 , enAddNewMode =3};

	enMode _Mode;
	string _UserName;
	string _Password;
	short _Permission; 
	bool _MarkForDelete = false; 

	static clsUser _ConvertLineToObject(string Line)
	{
		vector<string> vUser; 
		vUser = clsString::Split(Line, "#//#");
		return clsUser(enMode::enUpdateMode, vUser[0], vUser[1], vUser[2], vUser[3],
			vUser[4], clsUtil::DncrypText(vUser[5],2), stoi(vUser[6]));
	}
	


	static string _ConvertObjectToLine(clsUser User, string sep = "#//#")
	{
		string S1 = "";
		S1 += User.FirstName + sep;
		S1 += User.LastName + sep;
		S1 += User.Email + sep;
		S1 += User.Phone + sep;
		S1 += User.UserName + sep;

		S1 += clsUtil::EncryptText(User.Password ,2) + sep;
		S1 += to_string(User.Permission);
		return S1; 
	}
	static clsUser _GetEmptyUserObject()
	{
		
		return clsUser(enMode::enEmptyMode,"", "", "", "","","", 0);
	}
	static vector<clsUser> _LoadUserDataFromFile()
	{
		vector<clsUser> vUser;
		fstream myfile;
		myfile.open("Users.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsUser U = _ConvertLineToObject(line);
				vUser.push_back(U);

			}
			myfile.close();
		}
		return vUser;
	}
	void _SaveUserDataToFile(vector<clsUser> vUser)
	{
		fstream myfile; 
		myfile.open("Users.txt", ios::out); 
		if (myfile.is_open())
		{
			string DataLine; 
			for (clsUser U : vUser)
			{
				if (U.MarkedForDelete() == false)
				{
					DataLine = _ConvertObjectToLine(U);
					myfile << DataLine << endl; 
				}
			}
			myfile.close(); 
		}
	}
	void _Update()
	{
		vector<clsUser> _vUser;
		_vUser = _LoadUserDataFromFile();
		for (clsUser& U : _vUser)
		{
			if (U.UserName == UserName)
			{
				U = *this;
				break;
			}
		}
		_SaveUserDataToFile(_vUser);
	}
	void _AddDataLineToFile(string DataLine)
	{
		fstream myfile; 
		myfile.open("Users.txt", ios::out | ios::app); 
		if (myfile.is_open())
		{
			myfile << DataLine << endl; 
			myfile.close(); 
		}
	}
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertObjectToLine(*this));
	}
	string _PerpareLoginRecord(string sep = "#//#")
	{
		string LoginRecord = ""; 
		LoginRecord += clsDate::GetSystemDateTimeString() + sep; 
		LoginRecord += UserName + sep; 
		LoginRecord += Password + sep; 
		LoginRecord += to_string(Permission); 
		return LoginRecord; 
	}
	struct stLoginRegstorRecord1;
	static stLoginRegstorRecord1 _ConvertRegistorLineToRecord(string line, string sep = "#//#")
	{
		vector <string > vReg;
		stLoginRegstorRecord1 Reg;
		vReg = clsString::Split(line, sep); 

		Reg.DateTime = vReg[0]; 
		Reg.UserName = vReg[1];
		Reg.Password = vReg[2]; 
		Reg.Permission = stoi(vReg[3]); 
		return Reg; 

	}
	
public:
	
	struct stLoginRegstorRecord1
	{
		string DateTime;
		string UserName;
		string Password;
		short Permission;
	};


	enum enSaveResult {svFaildEmptyObject = 1 , svSuccessfull = 2 , svFaildUserExists = 3};

	enum enPermissions { eAll = -1 , epListClient = 1 , epAddClient = 2 , 
	epDeletClient = 4 , epUpdateClient = 8 , epFindClient = 16 , epTransaction = 32 , 
	epManagerUser = 64 , epLoginListUser = 128 };

	clsUser(enMode Mode , string FirstName , string LastName , string Email , string Phone 
	, string UserName , string Password , short Permission):
		clsPerson(FirstName , LastName , Email, Phone)
	{
		_Mode = Mode; 
		_UserName = UserName; 
		_Password = Password; 
		_Permission = Permission; 
	}
	void SetUserName(string username)
	{
		_UserName = username; 
	}
	string GetUserName()
	{
		return _UserName; 
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string password)
	{
		_Password = password; 
	}
	string GetPassword()
	{
		return _Password; 
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermission(short permission)
	{
		_Permission = permission; 
	}
	short GetPermission()
	{
		return _Permission; 
	}
	__declspec(property(get = GetPermission, put = SetPermission)) short Permission;
	bool MarkedForDelete()
	{
		return _MarkForDelete; 
	}
	static clsUser find(string UserName1)
	{
		vector<clsUser> vUser; 
		
		fstream myfile; 
		myfile.open("Users.txt", ios::in);

		if (myfile.is_open())
		{
			string line; 
			while (getline(myfile , line))
			{
					clsUser U = _ConvertLineToObject(line);
					if (U.UserName == UserName1)
					{
						
						return U; 
					}

			}
			myfile.close();
			
		}
		return _GetEmptyUserObject(); 
	}
	static clsUser find(string UserName1 , string password)
	{
		vector<clsUser> vUser;

		fstream myfile;
		myfile.open("Users.txt", ios::in);

		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsUser U = _ConvertLineToObject(line);
				if (U.UserName == UserName1 && U.Password == password)
				{
					myfile.close();
					return U;
				}
			}
			myfile.close();

		}
		return _GetEmptyUserObject();
	}

static void print(clsUser User)
	{
		cout << "-------------Find List ----------------\n"; 
		cout <<setw(3) << left << "First name is :" << User.FirstName << endl;
		cout << setw(3) << left << "Last name is :" << User.LastName << endl;
		cout << setw(3) << left << "User name is :" << User.UserName << endl;
		cout << setw(3) << left << "Password is  :" << User.Password << endl;
		cout << setw(3) << left << "\n-------------------------------------\n";
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::enEmptyMode);
	}

	static bool IsUserExit(string username)
	{
		clsUser user = find(username); 
		return (!user.IsEmpty());
	}

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case clsUser::enUpdateMode:
			_Update();
			return enSaveResult::svSuccessfull;
			break;
		case clsUser::enEmptyMode:
			if (IsEmpty())
			{
				return enSaveResult::svFaildEmptyObject; 
			}
			break;
		case clsUser::enAddNewMode:
			if (IsUserExit(_UserName))
			{
				return enSaveResult::svFaildUserExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::enUpdateMode; 
				return enSaveResult::svSuccessfull; 

			}
			break;
		
		}
	}

	bool Delete()
	{
		vector<clsUser> vUser; 
		vUser = _LoadUserDataFromFile(); 
		for (clsUser& U : vUser)
		{
			if (U.UserName == _UserName)
			{
				U._MarkForDelete = true;
				break; 
			}

		}
		_SaveUserDataToFile(vUser);
		*this = _GetEmptyUserObject(); 
		return true; 

     }
	
	 static vector<clsUser> GetUserList()
	{
		return _LoadUserDataFromFile(); 
	}
	 
	 static clsUser _GetAddUserObject(string UserName)
	 {

		 return clsUser(enMode::enAddNewMode, "", "", "", "", UserName, "", 0);
	 }

	bool CheckAccessPermission(enPermissions Permission)
	 {
		 if (this->Permission == enPermissions::eAll)
			 return true; 
		 if ((Permission & this->Permission) == Permission)
			 return true; 
		 else
		 {
			 return false; 
		 }
	 }
	 void SaveRegisterLogin() {
		fstream myfile;

		// Open file in append mode if you don't want to overwrite
		myfile.open("RegLogin.txt", ios::out | ios::app);
		if (!myfile.is_open()) {
			cerr << "Error: Could not open the file." << endl;
			return;
		}

		
		string line = _PerpareLoginRecord(); 
		
		
		myfile << line << endl;

		// File will close automatically, but manually closing for clarity
		myfile.close();
	}

	 static vector <stLoginRegstorRecord1> GetLoginRegisterList()
	 {
		 vector<stLoginRegstorRecord1> vRegistor;
		  
		 fstream Myfile; 
		 Myfile.open("RegLogin.txt", ios::in); 
		 if (Myfile.is_open())
		 {
			 string line; 
			 stLoginRegstorRecord1 Registor; 
			 
			 while (getline(Myfile, line ))
			 {
				 Registor = _ConvertRegistorLineToRecord(line , "#//#");
				 
				 vRegistor.push_back(Registor);
				 
			 }
			 Myfile.close();
			
		}
		 return vRegistor; 
	 }
};




