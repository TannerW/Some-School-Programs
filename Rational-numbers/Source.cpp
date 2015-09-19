//course: CS215-005
//Project: Lab Assignment 10
//Date: 04/15/2015
//Purpose: to properly simplify, manipulate, and display rational number
//Author: Owen Tanner Wilkerson

#include <iostream>
#include "Rational.h"

using namespace std;

void pause_215(bool have_newline)
{
	if (have_newline) {
		// Ignore the newline after the user's previous input.
		cin.ignore(256, '\n');
	}

	// Prompt for the user to press ENTER, then wait for a newline.
	cout << endl << "Press ENTER to continue." << endl;
	cin.ignore(256, '\n');
}

int main()
{
	Rational R1(33,33);
	Rational R2(180,240);
	R1.printR();
	R2.printR();
	R1.addR(R2);
	R1.printR();
	R1.setR(2,5);
	R1.subR(R2);
	R1.printR();
	R1.setR(2,5);
	R1.mulR(R2);
	R1.printR();
	R1.setR(2,5);
	R1.divR(R2);
	R1.printR();
	R2.printR();
	pause_215(false);
	return 0;
}
