//course: CS215-005
//Project: Lab Assignment 11
//Date: 04/24/2015
//Purpose: to simulate bank account transactions
//Author: Owen Tanner Wilkerson

#ifndef HEADERNAME_H_INCLUDED
#define HEADERNAME_H_INCLUDED

#include <iostream>
using namespace std;

class Account
{
public:
	//default constructor
	Account();

	//constructor
	Account(double balance);

	//used to deposit money into account
	void deposit(double amount);

	//used to withdraw money from account
	void withdraw(double amount);

	//calculates the daily interest and adds it to the balance
	void daily_interest(double interest_rate, double required_balance);

	//prints out the account balance
	void display_balance();

private:
	//amount of money in the account
	double balance;
};
#endif
