 /* 
 * File:   ShapePattern.cpp
 * Author: pike
 *
 * Created on April 25, 2015.
 */

#include "ShapePattern.h"

//this source code was given by instructor Yi Pike of University of Kentucky

//set up the default pattern as '*' star
ShapePattern::ShapePattern()
{
    pattern = '*';
}

//purpose: sets the pattern of the shape to another character
//description: sets the pattern of the shape to another character
//input: desired pattern
//output: n/a
void ShapePattern::set_pattern(char c)
{
    pattern = c;
}

//purpose: gets current pattern of object
//description: aquires the private data member that is the pattern
//input: n/a
//output: returns pattern
char ShapePattern::get_pattern() const
{
    return pattern;
}
