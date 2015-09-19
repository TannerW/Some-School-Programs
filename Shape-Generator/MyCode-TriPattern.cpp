#include "TriPattern.h"

//purpose: default constructor
//description: creates default object
//input: n/a
//output:n/a
TrianglePattern::TrianglePattern()
{
	height=0;
}

//purpose: constructor
//description: creates object
//input: desired private data
//output: a new object
TrianglePattern::TrianglePattern(int height)
{
	this -> height=height;
}

//purpose: changes private data member
//description: sets data member to desired integer
//input: desired integer
//output: the changed data member
void TrianglePattern::set_height(int height)
{
	this->height=height;
}

//purpose: applies recursion to print the pattern and the shape
//description: needed to assist the PrintPatern by using recursion to print the pattern
//input: n/a
//output: the shape and pattern
void TrianglePattern::printHelper()
{
	if (height<=0)
		return;

	for(int i=0; i<height;i++)
		cout<<get_pattern();
	cout<<endl;

	height--;
	printHelper();
}

//purpose:prints the pattern and shape
//description: uses the printHelper to print the pattern and shape
//input:n/a
//output: string saying the shape and private data members and the pattern and shape
void TrianglePattern::printPattern()
{
	if (height <=0)
		height=0;
	cout<<"The Right Triangle Pattern: (height="<<height<<")"<<endl;
	printHelper();
	cout<<endl;
}
