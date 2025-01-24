#pragma once
#include<iostream>
using namespace std; 
#include"clsPerson.h"
#include<vector>
#include<fstream>
#include"clsString.h"

class clsBankClients : public clsPerson
{
private:
	
	
	enum enMode { UpdateMode, EmptyMode , AddNewMode};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode; 
	float _AccountBalance; 
	bool _MarkForDelete = false;

	static clsBankClients _ConvertLineToObject(string Line)
	{
		vector<string> vClient;
		vClient = clsString::Split(Line, "#//#"); 

		return clsBankClients(enMode::UpdateMode, vClient[0], vClient[1], vClient[2],
		vClient[3], vClient[4], vClient[5], stod(vClient[6]));
		
	}
	static string _ConvertObjectToLine(clsBankClients Client)
	{
		string stClient;
		string Sep = "#//#";
		stClient += Client.FirstName + Sep;
		stClient += Client.LastName + Sep; 
		stClient += Client.Email + Sep; 
		stClient += Client.Phone + Sep; 
		stClient += Client._AccountNumber + Sep; 
		stClient += Client._PinCode + Sep;
		stClient += to_string(Client._AccountBalance); 

		return stClient; 
	}
		
	static clsBankClients _GetEmptyClientObject()
	{
		return clsBankClients(enMode::EmptyMode, "", "", "", "", "", "", 0); 
	}
	
	// Take data from file 
	static vector<clsBankClients> _LoadClientDataFromFile()
	{
		vector<clsBankClients> vClient; 
		fstream myfile; 
		myfile.open("Client.txt", ios::in); 
		if (myfile.is_open())
		{
			string line; 
			while (getline(myfile, line))
			{
				clsBankClients Client = _ConvertLineToObject(line); 
				vClient.push_back(Client); 


			}
			myfile.close();
		}
		return vClient; 
	}

	// Save data to file 
	static void _SaveClientDataToFile(vector<clsBankClients> vClient)
	{
		fstream myfile; 
		myfile.open("Client.txt", ios::out); 
		if (myfile.is_open())
		{
			string line;
			
			for (clsBankClients C : vClient)
			{
				if (C._MarkForDelete == false)
				{
					line = _ConvertObjectToLine(C);
					myfile << line << endl;
				}
				
			}
			myfile.close();
		}
		
	}
	string _PrepareTransfarLogRecord(float amount, clsBankClients DestinationClient,
		string username, string sep = "#//#")
	{
		string TransfarLogRecord = "";
		TransfarLogRecord += clsDate::GetSystemDateTimeString() + sep; 
		TransfarLogRecord += AccountNumber() + sep; 
		TransfarLogRecord += DestinationClient.AccountNumber() + sep; 
		TransfarLogRecord += to_string(amount) + sep; 
		TransfarLogRecord += to_string(AccountBalance) + sep; 
		TransfarLogRecord += to_string(DestinationClient.AccountBalance) + sep; 
		TransfarLogRecord += username; 
		return TransfarLogRecord; 
	}
	
	 void _RegistorTransfarLog(float amount , clsBankClients DestinationClient , string username)

	{
		 string stDataLine = _PrepareTransfarLogRecord(amount, DestinationClient, username);

			 fstream myfile; 
			 myfile.open("TransLog.txt", ios::out | ios::app); 
			 if (myfile.is_open())
			 {
				 myfile << stDataLine << endl; 
				 myfile.close(); 
			 }
	}

	 struct stTransfarLogin; 
	 static stTransfarLogin _ConvertTransfarLogLineToObject(string line , string  sep = "#//#")
	 {
		 vector<string > vTransfar; 
		 stTransfarLogin Transfar; 
		 vTransfar = clsString::Split(line, sep); 
		 Transfar.DateTime = vTransfar[0]; 
		 Transfar.SourceAccountNumber = vTransfar[1]; 
		 Transfar.DestinationAccountNumber = vTransfar[2]; 
		 Transfar.Amount = stoi(vTransfar[3]); 
		 Transfar.stBalanceAfter = stoi(vTransfar[4]); 
		 Transfar.dedBalanceAfter = stoi(vTransfar[5]); 
		 Transfar.username = vTransfar[6]; 

		 return Transfar;
	 }

public:
	struct stTransfarLogin 
	{
		string DateTime;
		string SourceAccountNumber; 
		string DestinationAccountNumber; 
		float Amount; 
		float stBalanceAfter;
		float dedBalanceAfter; 
		string username; 

	 };
	
	clsBankClients(enMode Mode , string FirstName, string LastName, string Email,
		string Phone, string AccountNumber,
		string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber; 
		_PinCode = PinCode; 
		_AccountBalance = AccountBalance; 
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber; 
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";
	}

	
	static clsBankClients find(string AccountNumber)
	{
		fstream myfile; 
		myfile.open("Client.txt", ios::in); 
		if (myfile.is_open())
		{
			string Line; 
			while (getline(myfile, Line))
			{
				clsBankClients Client = _ConvertLineToObject(Line); 
				if (Client._AccountNumber == AccountNumber)
				{
					myfile.close(); 
					return Client;
				}
				


			}
			myfile.close();
			return _GetEmptyClientObject();
		}


	}
	 bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	 static bool IsClientExist(string AccountNumber)
	 {
		 clsBankClients Client1 = find(AccountNumber); 
		 return (!Client1.IsEmpty());
	 }

	 void Update()
	 {
		 vector<clsBankClients>vClient; 
		 vClient = _LoadClientDataFromFile(); 
		 for (clsBankClients& C : vClient)
		 {
			 if (C.AccountNumber() == AccountNumber())
			 {
				 C = *this; 
				 break; 
			 }
		 }
		 _SaveClientDataToFile(vClient); 
	 }

	 void AddDataLineToFile(string DataLine)
	 {
		 fstream myfile;
		 myfile.open("Client.txt", ios::out | ios::app);
		 if (myfile.is_open())
		 {
			 myfile << DataLine << endl;
			 myfile.close();
		 }
	 }

	 void AddNew()
	 {
		 AddDataLineToFile(_ConvertObjectToLine(*this));
	 }
	 

	 enum enSaveResult { svFieldEmptyObject, svSucceeded , svFaildAccountNumberExists};

	 enSaveResult Save()
	 {
		 switch (_Mode)
		 {
		 case clsBankClients::UpdateMode:
			 Update();
			 return enSaveResult::svSucceeded;
			 
		 case clsBankClients::EmptyMode:
			 return enSaveResult::svFieldEmptyObject;
		 
		 case clsBankClients::AddNewMode: 
			 if (IsClientExist(_AccountNumber))
			 {
				 return enSaveResult::svFieldEmptyObject; 
			 }
			 else
			 {
				 AddNew();
				 _Mode = enMode::UpdateMode;
				 return enSaveResult::svSucceeded; 
			 }
		 }
	 }
	 static clsBankClients GetAddNewClientObject(string AccountNumber)
	 {
		 return clsBankClients(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	 }

	 bool Delete()
	 {
		 vector<clsBankClients> _vClient; 
		 _vClient = _LoadClientDataFromFile();
		 for (clsBankClients& C : _vClient)
		 {
			 if (C.AccountNumber() == _AccountNumber)
			 {
				 C._MarkForDelete = true; 
				 break; 
			 }
		 }
		 _SaveClientDataToFile(_vClient); 
		 *this = _GetEmptyClientObject(); 
		 return true; 
	 }
	 static vector<clsBankClients> GetClientList()
	 {
		 return _LoadClientDataFromFile(); 
	 }

	 static float GetTotalBalance()
	 {
		 vector<clsBankClients> vClient = GetClientList();
		 double TotalBalance = 0;
		 for (clsBankClients C : vClient)
		 {
			 TotalBalance += C.AccountBalance;
		 }
		 return TotalBalance; 
	 }

	  void Deposit(double Amount)
	 {
		 _AccountBalance += Amount; 
		 Save(); 
	 }

	  bool WithDraw(double Amount)
	  {
		  if (_AccountBalance < Amount)
		  {
			  return false; 
		  }
		  else
		  {
			  _AccountBalance -= Amount; 
			  Save();
		  }
	  }

	  bool Transfar(float Amount, clsBankClients& DestinationClient , string username)
	  {
		  if (Amount > AccountBalance)
		  {
			  return false; 
		  }
		  WithDraw(Amount); 
		  DestinationClient.Deposit(Amount); 
		  _RegistorTransfarLog(Amount, DestinationClient, username); 
		  return true; 
	  }

	  static vector<stTransfarLogin> GetTransfarLoginList()
	  {
		  vector<stTransfarLogin > vTransfar; 
		  stTransfarLogin Transfar; 
		  fstream myfile; 
		  myfile.open("TransLog.txt", ios::in); 
		  if (myfile.is_open())
		  {
			  string line; 
			  while (getline(myfile,line))
			  {
				  Transfar = _ConvertTransfarLogLineToObject(line); 
				  vTransfar.push_back(Transfar); 

			  }
				  myfile.close();
		  }
		  return vTransfar; 
	  }

};

