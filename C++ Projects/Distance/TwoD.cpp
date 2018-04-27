/*  Jonathan Brashears
    Homework 4
    CS 102
    Distance Calculator
*/
#include <iostream>
#include <cmath>
#include "OneD.h"
#include "TwoD.h"

using namespace std;

//default constructor
TwoD::TwoD()
{
    x = 0; //holds x value
    y = 0; //holds y value
}

//constructor that sets x and y
TwoD::TwoD(int CoordOne, int CoordTwo)
{
    x = CoordOne; //sets x to user input
    y = CoordTwo; //sets y to user input
}

//getter
int TwoD::getY()
{
    return y; //returns y
}

//Calculates and outputs the distance between a 2-d and 1-d point
void TwoD::CalcDistance(OneD PointTwo)
{
    cout << "The distance between the points is: " << sqrt(((x - PointTwo.getX())*(x - PointTwo.getX()))+(y*y));
}
//Calculates and outputs the distance between a two 2-d points
void TwoD::CalcDistance(TwoD PointTwo)
{
   cout << "The distance between the points is: " << sqrt((x-PointTwo.getX())*(x-PointTwo.getX())+(y-PointTwo.getY())*(y-PointTwo.getY()));
}
