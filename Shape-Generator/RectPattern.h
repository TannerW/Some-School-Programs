#ifndef RECT_H
#define RECT_H

#include <iostream>
#include "ShapePattern.h"
using namespace std;

class RectanglePattern : public ShapePattern
{
public:
	//default constructor
	RectanglePattern();

	//constructor
	RectanglePattern(int length, int width);

	//prints the pattern of rectangle
	void printPattern();

	//prints the pattern (needed for recursion)
	void printHelper();

	//changes private variable
	void set_length(int length);

	//changes private variable
	void set_width(int width);
private:
	int length, width;

};
#endif
