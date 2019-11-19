//.....Name: Nima Naimi
//.....Date: January 6th, 2018
//.....Assignment #1: Height
//.....Description: Header file for Height class. Stores height as components
//................. in feet and inches.

#ifndef HEIGHT_H
#define HEIGHT_H
#include <string>

using namespace std;

class Height
{
    public:
        Height(int feet, int inches); // Default constructor
        void setHeight(int feet, int inches); // Overwrites height values with
                                              // new values
        void add(int inches); // Adds a value in inches to the existing
                              // height values
        string toString() const; // Converts and returns a string containing
                                 // the height values in feet and inches.
    private:
        int feet {0};
        int inches {0};
};

#endif // HEIGHT_H
