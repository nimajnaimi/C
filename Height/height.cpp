//.....Name: Nima Naimi
//.....Date: January 6th, 2018
//.....Assignment #1: Height
//.....Description: This class sets and adds values to a height object in
//................. feet and inches.

#include "height.h"
#include <iostream>
#include <string>

using namespace std;

// Constructs an object of type Height
Height::Height(int feet, int inches)
{
    this->feet = feet;
    this->inches = inches;
}

// Overwrites height values with new feet and inches passed parameters
void Height::setHeight(int feet, int inches)
{
    this->feet = feet;
    this->inches = inches;
}

// Returns the feet and inches of the object as a string with
// format "feet'inches''"
string Height::toString() const
{
    return to_string(this->feet) + "'" + to_string(this->inches) + "''";
}

// Adds a passed value amount of inches to the object. Will adjust inches and
// feet depending on resulting values.
void Height::add(int inches)
{
    this->inches += inches;
    while (this->inches >= 12) // Convert inches to feet
    {
        this->feet++;
        this->inches += -12;
    }
}
