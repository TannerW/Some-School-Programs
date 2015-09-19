//course: CS215-005
//Project: Lab Assignment 9
//Date: 04/8/2015
//Purpose: to use a class to properly simulate a clock
//Author: Owen Tanner Wilkerson

#ifndef HEADERNAME_H_INCLUDED
#define HEADERNAME_H_INCLUDED

#include <iostream>
using namespace std;

class Clock
{
public:
	Clock(); // default constructor

	Clock(int hh, int mm, int ss); //constructor

	//increase time by sec seconds
	void incrementSeconds(int sec);

	//increase time by min minutes
	void incrementMinutes(int min);

	//increase time by hh hours,
	//if hours reach 24, simply wrap around to 0.
	void incrementHours(int hh);

	void addTime(Clock C); //add C into the clock

	//print time in hours:minutes:seconds am(or pm) format
	void printTime();

private:
	// Declare data members of the class
	// 0 <= hours < 24, 0 <= minutes < 60, 0 <= seconds < 60
	int hours, minutes, seconds;

};

#endif
