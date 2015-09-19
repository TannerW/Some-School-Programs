 /* 
 * File:   ShapePattern.h
 * Author: pike
 *
 * Created on April 25, 2015.
 */

//This header was given by the instructor Yi Pike of University of Kentucky

#ifndef SHAPEPATTERN_H
#define	SHAPEPATTERN_H

class ShapePattern
{
public:
    ShapePattern(); //constructor
    void set_pattern(char c); //changes pattern
    char get_pattern() const; //requests current pattern
    virtual void printPattern() = 0; //vitual needed for override

private:
    char pattern;
};
#endif	/* SHAPEPATTERN_H */

