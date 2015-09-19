//course: CS215-005
//Project: Lab Assignment 9
//Date: 04/8/2015
//Purpose: to use a class to properly simulate a clock
//Author: Owen Tanner Wilkerson

#include <iostream>
#include "Clock.h"

//constructor
Clock::Clock(int hh, int mm, int ss)
{
	hours=hh;
	minutes=mm;
	seconds=ss;
}

//adds the hour, minute, and second data members of the parameter to the objects hour, minute, and second data members
void Clock::addTime(Clock C)
{
	incrementHours(C.hours);
	incrementMinutes(C.minutes);
	incrementSeconds(C.seconds);
}

//function that properly interprets twelve hour time from 24 hour time and print the time and AM or PM
void Clock::printTime()
{
	int TwelveHourTime=hours;

	if(hours>12) //anything above 12 in 24 hour time is equivilant to that number minus 12 in twelve hour time
		TwelveHourTime=hours-12;

	if(hours==00) //if 24 hour time is 00 then it is 12 AM in twelve hour time
		TwelveHourTime=12;

	cout<<TwelveHourTime<<":"<<minutes<<":"<<seconds;

	if (hours>11) //from 12 to 23 in 24 hour time is PM
		cout<<" PM"<<endl;
	else //from 00 to 11 in 24 hour time is AM
		cout<<" AM"<<endl;
}

//a function to add a number to the seconds data member and properly round and loop the clock when needed 
void Clock::incrementSeconds(int sec)
{
	for(int i=0;i<sec;i++)
	{
		seconds+=1;
		if(seconds>59)
		{
			seconds=00;
			incrementMinutes(1);
		}
	}
}

//a function to add a number to the minutes data member and properly round and loop the clock when needed 
void Clock::incrementMinutes(int min)
{
	for(int i=0;i<min;i++)
	{
		minutes+=1;
		if(minutes>59)
		{
			minutes=00;
			incrementHours(1);
		}
	}
}

//a function to add a number to the hours data member and properly round and loop the clock when needed 
void Clock::incrementHours(int hh)
{
	for(int i=0;i<hh;i++)
	{
		hours+=1;
		if(hours>23)
		{
			hours=00;
		}
	}
}
