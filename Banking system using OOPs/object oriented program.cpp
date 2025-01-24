
#include<iostream>
#include"clsMainScreen.h"
#include"clsUser.h"
#include"clsLoginScreen.h"
#include<vector>
#include"clsString.h"
#include"clsCurrency.h"

void print(clsCurrency Currency)
{
	cout << "Currency name : " << Currency.GetCurrencyName(); 
}


int main()
{
	while (true)
	{
		clsLoginScreen::ShowLoginScreen();
	}

	
	/*clsCurrency NewCurrency = clsCurrency::FindByCountry("Yemen"); 
	print(NewCurrency); 
	*/
	

	return 0; 
}