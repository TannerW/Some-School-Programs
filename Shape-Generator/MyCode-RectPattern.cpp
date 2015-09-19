#include "RectPattern.h"
using namespace std;

//purpose: default constructor
//description: creates default object
//input: n/a
//output:n/a
RectanglePattern::RectanglePattern()
{
	length=0;
	width=0;
}

//purpose: constructor
//description: creates object
//input: desired private data
//output: new object
RectanglePattern::RectanglePattern(int legnth, int width)
{
	this -> length = length;
	this -> width = width;
}

//purpose: changes private data member
//description: sets data member to desired integer
//input: desired integer
//output: the changed data member
void RectanglePattern::set_length(int length)
{
	this->length=length;
}

//purpose: changes private data member
//description: sets data member to desired integer
//input: desired integer
//output: the changed data member
void RectanglePattern::set_width(int width)
{
	this->width=width;
}

//purpose: applies recursion to print the pattern and the shape
//description: needed to assist the PrintPatern by using recursion to print the pattern
//input: n/a
//output: the shape and pattern
void RectanglePattern::printHelper()
{
	if (width<=0||length<=0)
		return;

		for(int j=0; j<length;j++)
			cout<<get_pattern();
		cout<<endl;

	width--;
	printHelper();
}

//purpose:prints the pattern and shape
//description: uses the printHelper to print the pattern and shape
//input:n/a
//output: string saying the shape and private data members and the pattern and shape
void RectanglePattern::printPattern()
{
	if (width<=0||length<=0)
	{
		width=0;
		length=0;
	}
	cout<<"The Rectangle Pattern: (length="<<length<<": width="<<width<<")"<<endl;
	printHelper();
	cout<<endl;
}
