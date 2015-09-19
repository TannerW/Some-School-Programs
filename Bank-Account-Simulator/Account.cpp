//course: CS215-005
//Project: Lab Assignment 11
//Date: 04/24/2015
//Purpose: to simulate bank account transactions
//Author: Owen Tanner Wilkerson

#include <iostream>
#include "Account.h"

using namespace std;

//purpose: default constructor
//description: construct an object
//inputs: n/a
//outputs: n/a
Account::Account()
{
	balance=0;
}

//purpose: constructor
//description: construct an object
//inputs: n/a
//outputs: n/a
Account::Account(double balance)
{
	this->balance=balance;
}

//purpose: deposit money to the account balance
//description: adds an amount to the account balance data member
//inputs:amount to add to the balance
//outputs: n/a
void Account::deposit(double amount)
{
	balance+=amount;
}

//purpose: withdraw money from the account
//description: subtracts an amount from the account balance if there is enough money in the account if not then it gives an error
//inputs: amount to subtract from the balance
//outputs: n/a
void Account::withdraw(double amount)
{
	if (balance<amount)
	{
		cout<<"Your balance is less than "<<amount<<". Withdrawal failed."<<endl;
	}
	else
	{
		balance-=amount;
	}
}

//purpose: add the daily interest to the account balance
//description: adds the interest to the account balance
	//after checking to see if there is enough money in the account to accumulate interest and calculating the interest 
//inputs:interest rate and amount required for interest to begin accumulating
//outputs: n/a
void Account::daily_interest(double interest_rate,double required_balance)
{
	if(balance>required_balance)
	{
	balance+=(balance*((interest_rate/100)/360));
	}
}

//purpose: print the account balance of the account
//description: prints balance
//inputs: n/a
//outputs: n/a
void Account::display_balance()
{
	cout<<balance;
}
