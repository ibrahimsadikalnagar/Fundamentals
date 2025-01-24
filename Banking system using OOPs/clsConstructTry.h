#pragma once
#include<iostream>
using namespace std; 
class clsConstructTry
{
private:
	string _FirstName; 
	string _LastName; 
	short _age; 
	float salaries; 
public:
	clsConstructTry(string firstname , string lastname , short age)
	{
		_FirstName = firstname; 
		_LastName = lastname; 
		_age = age; 
	}
	void SetFirstName(string firstname)
	{
		_FirstName = firstname; 
	}
	string GetFirstName()
	{
		return _FirstName; 
	}
	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
	
	static clsConstructTry find()
	{
		return clsConstructTry("Ibrahim" , "alnagar" , 41);

	}
	void print()
	{
		cout << "\nFirst name is "<< FirstName;
		cout << "\nLast Namw is " << _LastName; 
	}
	
};

