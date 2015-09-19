//course: CS215-005
//Project: Lab Assignment 10
//Date: 04/15/2015
//Purpose: to properly simplify, manipulate, and display rational number
//Author: Owen Tanner Wilkerson

#include <iostream>
#include "Rational.h"

using namespace std;

//purpose: default constructor
//description: default construct an object
//inputs: N/A
//outputs: creates a new object
Rational::Rational()
{
	num=0;
	den=1;
}

//purpose:constructor
//description: constructor with specific parameters
//inputs: the desires private member values of the new object
//outputs: creates new object
Rational::Rational(int num, int den)
{
	this->num=num;
	this->den=den;
}

//purpose: to simplify and print the fraction
//description: simplifies the fraction to its most reduced form 
//inputs:N/A
//outputs:the reduced fraction of the object called
void Rational::printR()
{
	int printNum=num;
	int printDen=den;

	//simplification if the top and bottom equals
	if(den==num)
	{
		printDen=1;
		printNum=1;
	}

	//find greatest common factor of the to fractions in order to simplify
	else
	{
		int temp;

		for(int i=2; i<den; i++)
		{
			if(num%i == 0 && den%i ==0)
			{
				temp=i;
			}
		}
		printNum=num/temp;
		printDen=den/temp;
	}

	cout<<printNum<<"/"<<printDen<<endl;
}

//purpose:change the private data members of an object to desires integers
//description: sets the private data members to the parameters inputted
//inputs: desired numerator and denominator
//outputs: N/A
void Rational::setR(int num, int den)
{
	//sets the data members to parameters
	this->num=num;
	this->den=den;
}

//purpose: add two fractions together
//description:finds the common denominator and adds by use of an algorithm and finds new numerator
//inputs:the object you wish to add to the object
//outputs: malipulates the object
void Rational::addR(Rational R)
{
	//finds common denominators and adds the fraction together 
	int newNum,newDen;
	newNum=((num*R.den)+(den*R.num));
	newDen=den*R.den;
	num=newNum;
	den=newDen;
}

//purpose: subtract two fractions
//description: finds the common denominators and subracts by use of an algorithm and finds the new numerator 
//inputs:the object you wish to subtract
//outputs:manipulates the object
void Rational::subR(Rational R)
{
	//finds common denominators and subtracts the fractions
	int newNum,newDen;
	newNum=((num*R.den)-(den*R.num));
	newDen=den*R.den;
	num=newNum;
	den=newDen;
}

//purpose:multiply two fractions
//description:muliplies the denominators and numerators to show the multiplication of two fractions
//inputs:the object you wish to multiply by
//outputs: manipulates the object
void Rational::mulR(Rational R)
{
	//multiply the fractions together
	int newNum,newDen;
	newNum=num*R.num;
	newDen=den*R.den;
	num=newNum;
	den=newDen;
}

//purpose: divide to fractions
//description: flips the fraction in the denominator and multiplies the two fraction together
//inputs: the object you wish to divide by
//outputs: manipulates the object
void Rational::divR(Rational R)
{
	//flips the fraction in the denominator and multiply it by the numerator
	int temp;
	temp=R.num;
	R.num=R.den;
	R.den=temp;
	int newNum,newDen;
	newNum=num*R.num;
	newDen=den*R.den;
	num=newNum;
	den=newDen;
}
