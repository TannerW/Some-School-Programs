//course: CS215-005
//Project: Lab Assignment 11
//Date: 04/24/2015
//Purpose: to simulate bank account transactions
//Author: Owen Tanner Wilkerson

#ifndef Checking_H
#define Checking_H

#include <iostream>
#include "Account.h"

using namespace std;

class Checking : public Account
{
public:
	//default constructor
	Checking();

	//constructor
	Checking(double balance);

	//calculates the daily interest of the account balance
	void daily_interest();

	//prints out the account balance
	void display_balance();
private:
};
#endif
