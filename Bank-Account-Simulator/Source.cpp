//course: CS215-005
//Project: Lab Assignment 11
//Date: 04/24/2015
//Purpose: to simulate bank account transactions
//Author: Owen Tanner Wilkerson

#include <iostream>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"

using namespace std;

int main()
{
	double sav, che;
	cout << "Please input the balance for Checking account: "
		<< endl;
	cin >> che;
	cout << "Please input the balance for Savings account: "
		<< endl;
	cin >> sav;

	Checking c(che); //constructor
	Savings s(sav); //constructor

	for (int j = 1; j <= 30; j++)
	{
		c.withdraw(j * 2);
		c.deposit(j * 5);
		c.withdraw(j* 5);
		s.deposit(j * 5);
		s.withdraw(j * 2);
		c.daily_interest();
		s.daily_interest();
		if(j%10==0) //runs every 10 days
		{
			cout<<"day "<<j<<endl;
			c.display_balance();
			s.display_balance();
		}
	}

	system("pause");
	return 0;
}
