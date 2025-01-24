#pragma once
#include<iostream>

using namespace std; 
class InterfaceCommunication
{
public:

	virtual void SendSms(string name, short age) = 0; 

};

