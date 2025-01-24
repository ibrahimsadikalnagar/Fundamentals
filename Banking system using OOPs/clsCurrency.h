#pragma once
#include<iostream>
#include<vector>
#include<string.h>
#include"clsString.h"
#include <string>
#include<fstream>
using namespace std; 

class clsCurrency
{
private:
	enum enMode{ eUpdateMode , eEmptyMode };

	enMode _Mode; 
	string _Country; 
	string _CurrencyCode; 
	string _CurrencyName; 
	float _Rate; 

	static clsCurrency _ConvertLineToObject(string line, string sep = "#//#")
	{
		vector<string> vCurrency; 
		vCurrency = clsString::Split(line, sep); 

		return clsCurrency(enMode::eUpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stod(vCurrency[3]));
	}
	static string _ConvertObjectToLine(clsCurrency CurrenyObject , string sep = "#//#")
	{
		string S1 = "";
		S1 += CurrenyObject.GetCountry() + sep; 
		S1 += CurrenyObject.GetCurrencyCode() + sep;
		S1 += CurrenyObject.GetCurrencyName() + sep;
		S1 += to_string(CurrenyObject._Rate) + sep;

	}
	static vector<clsCurrency> _LoadCurrancyDataFromFile()
	{
		vector<clsCurrency> vCurrency; 
		
		fstream myfile; 
		myfile.open("Currencies.txt", ios::in); 
		if (myfile.is_open())
		{
			string line; 
			while (getline(myfile,line))
			{
				for (clsCurrency& C : vCurrency)
				{
					C = _ConvertLineToObject(line);
					vCurrency.push_back(C); 
				}
			}
			myfile.close();
		}
		return vCurrency; 
	}

	static void _SaveCurrencyDataToFile(vector<clsCurrency> vCurrency)
	{
		fstream myfile; 
		myfile.open("Currencies.txt", ios::out); 
		if (myfile.is_open())
		{
			string DataLine; 
			for (clsCurrency C : vCurrency)
			{
				DataLine = _ConvertObjectToLine(C); 
				myfile << DataLine << endl; 

			}
			myfile.close(); 
		}

	}
	void _Update()
	{
		vector<clsCurrency> _vCurrency; 
		_vCurrency = _LoadCurrancyDataFromFile();
		for (clsCurrency& C : _vCurrency)
		{
			if (C.GetCurrencyCode() == GetCurrencyCode())
			{
				C = *this; 
				break; 
			}
		}
	}
	static clsCurrency _GetEmptyCurrencyObject()
	{

		return clsCurrency(enMode::eEmptyMode, "", "", "", 0); 
	}

public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode; 
		_Country = Country; 
		_CurrencyCode = CurrencyCode; 
		_CurrencyName = CurrencyName; 
		_Rate = Rate; 
	}
	string  GetCountry()
	{
		return _Country;
	}
	string GetCurrencyCode()
	{
		return _CurrencyCode; 

	}
	string GetCurrencyName()
	{
		return _CurrencyName; 
	}
	float Rate()
	{
		return _Rate;
	}
	void UpdateRate(float NewRate)
	{
		_Rate = NewRate; 
		_Update(); 
	}
	
	bool IsEmpty()
	{
		return (_Mode == enMode::eEmptyMode); 
	}
	
	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode); 
		fstream myfile; 
		myfile.open("Currencies.txt", ios::in);
		if (myfile.is_open())
		{
			string line; 
			while (getline(myfile, line))
			{
				clsCurrency Currency = _ConvertLineToObject(line); 
				if (Currency.GetCurrencyCode() == CurrencyCode)
				{
					myfile.close(); 
					
						
				}

			}
				myfile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);
		fstream myfile;
		myfile.open("Currencies.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsCurrency Currency = _ConvertLineToObject(line);
				if (Currency.GetCountry() == Country)
				{
					myfile.close();

					return Currency; 
				}

			}
			myfile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());
	}

	static vector<clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrancyDataFromFile();
	}
};

