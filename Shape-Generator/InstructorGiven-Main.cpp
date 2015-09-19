 //course: CS215-005
 //Project: Lab Assignment 12
 //Date: 04/29/2015
 //Purpose: create a collection of mixed objects of different classes derived
 //         from the ShapePattern class using a vector of pointers pointing to
 //         to the base class object. The polymorphic behavior occurs when
 //         calling a virtual function with dynamic binding. 
 //         
 //Author: Owen Tanner Wilkerson (and Yi Pike on given files)

#include <iostream>
#include <vector>
#include "RectPattern.h"
#include "ShapePattern.h"
#include "TriPattern.h"

using namespace std;

void pause_215(bool have_newline);

//main function given by instructor Yi Pike of University of Kentucky
int main()
{
    const int SIZE = 4; 
    vector<ShapePattern*> shapes(SIZE);
    RectanglePattern* R0 = new RectanglePattern;
    R0->set_length(10);
    R0->set_width(5);
    shapes[0] = R0;
    shapes[1] = new RectanglePattern(7 , -4);
    TrianglePattern* T0 = new TrianglePattern;
    T0->set_height(8);
    shapes[2] = T0;
    shapes[3] = new TrianglePattern(12);
    shapes[3]->set_pattern('#');

    for (int i = 0; i < SIZE; i++) //runs print pattern for all the current objects
        shapes[i]->printPattern();

    for (int i = 0; i < SIZE; i++) //delete allocated objects
        delete shapes[i];
 
    pause_215(false);
    return 0;
}


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
