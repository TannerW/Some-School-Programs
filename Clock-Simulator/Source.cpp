//course: CS215-005
//Project: Lab Assignment 9
//Date: 04/8/2015
//Purpose: to use a class to properly simulate a clock
//Author: Owen Tanner Wilkerson

#include <iostream>
#include "Clock.h"

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
	Clock C1(0,0,0); //construct
	Clock C2(12,35,59); //construct
	C1.addTime(C2);
	C1.printTime();
	C2.printTime();
	C1.incrementSeconds(1);
	C1.printTime();
	C1.incrementMinutes(100);
	C1.printTime();
	C1.incrementHours(10);
	C1.printTime();
	C2.printTime();

	pause_215(false);
	return 0;
}
