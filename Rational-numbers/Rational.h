//course: CS215-005
//Project: Lab Assignment 10
//Date: 04/15/2015
//Purpose: to properly simplify, manipulate, and display rational number
//Author: Owen Tanner Wilkerson

#ifndef HEADERNAME_H_INCLUDED
#define HEADERNAME_H_INCLUDED

#include <iostream>
using namespace std;

class Rational
{
public:
	Rational();

	Rational(int num, int den);

	void printR();

	void setR(int num, int den);

	void addR(Rational R);

	void subR(Rational R);

	void mulR(Rational R);

	void divR(Rational R);

private:
	int num, den;
};

#endif
