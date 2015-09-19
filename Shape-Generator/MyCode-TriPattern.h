#ifndef TRI_H
#define TRI_H

#include <iostream>
#include "ShapePattern.h"
using namespace std;

class TrianglePattern : public ShapePattern
{
public:
	//default constructor
	TrianglePattern();

	//constructor
	TrianglePattern(int height);

	//prints the pattern of triangle
	void printPattern();

	//prints the pattern (needed for recursion)
	void printHelper();

	//changes private variable
	void set_height(int height);
private:
	int height;

};
#endif
