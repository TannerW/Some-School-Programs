//course: CS215-005
//Project: Lab Assignment 11
//Date: 04/24/2015
//Purpose: to simulate bank account transactions
//Author: Owen Tanner Wilkerson

#include <iostream>
#include "Checking.h"
#include "Account.h"
#include "Savings.h"

using namespace std;

//purpose: default constructor
//description: construct an object
//inputs: n/a
//outputs: n/a
Checking::Checking()
{
}

//purpose: constructor
//description: construct an object
//inputs: n/a
//outputs: n/a
Checking::Checking(double initial_amount):Account(initial_amount)
{
}

//purpose: add the daily interest to the account balance
//description: adds the interest to the account balance
	//after checking to see if there is enough money in the account to accumulate interest and calculating the interest 
//inputs:interest rate and amount required for interest to begin accumulating
//outputs: n/a
void Checking::daily_interest()
{
	Account::daily_interest(3,1000); //uses overriding to access the private data
}

//purpose: print the account balance of the account
//description: prints balance
//inputs: n/a
//outputs: n/a
void Checking::display_balance()
{
	cout<<"Checking balance: ";
	Account::display_balance(); //uses overriding to access the private data
	cout<<endl;
}
