#pragma once
#include<iostream>
using namespace std; 

class ClsInteger
{
private:
	short _value; 
public:
	ClsInteger()
	{
		_value = 0; 
	}
	ClsInteger(short value)
	{
		_value = value;
	}
	void SetInteger(short intr)
	{
		_value = intr; 
	}
	short GetInter()
	{
		return _value; 
	}
	static short CountInteger(short intr)
	{
		short count = 0; 
		for (short i = 0; i < intr; i++)
		{
			count += intr; 
		}
		return count; 
	}

	 short CountInteger()
	{
		return CountInteger(_value); 
	}
	 __declspec(property(get = GetInter, put = SetInteger)) short value; 
};


