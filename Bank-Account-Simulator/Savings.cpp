//course: CS215-005
//Project: Lab Assignment 11
//Date: 04/24/2015
//Purpose: to simulate bank account transactions
//Author: Owen Tanner Wilkerson

#include <iostream>
#include "Savings.h"
#include "Account.h"
#include "Checking.h"

using namespace std;

//purpose: default constructor
//description: construct an object
//inputs: n/a
//outputs: n/a
Savings::Savings()
{
}

//purpose: constructor
//description: construct an object
//inputs: n/a
//outputs: n/a
Savings::Savings(double initial_amount):Account(initial_amount)
{
}

//purpose: add the daily interest to the account balance
//description: adds the interest to the account balance
	//after checking to see if there is enough money in the account to accumulate interest and calculating the interest 
//inputs:interest rate and amount required for interest to begin accumulating
//outputs: n/a
void Savings::daily_interest()
{
	Account::daily_interest(6,0); //uses overriding to access the private data
}

//purpose: print the account balance of the account
//description: prints balance
//inputs: n/a
//outputs: n/a
void Savings::display_balance()
{
	cout<<"Savings balance: ";
	Account::display_balance(); //uses overriding to access the private data
	cout<<endl;
}
