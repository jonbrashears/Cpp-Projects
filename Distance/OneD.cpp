/*  Jonathan Brashears
    Homework 4
    CS 102
    Distance Calculator
*/


#include <iostream>
#include <cmath>
#include "OneD.h"

using namespace std;

//implementation of OneD class

//default constructor
OneD::OneD()
{
    x = 0;
}
//constructor from user input
OneD::OneD(int CoordOne)
{
    x = CoordOne;
}

//getter
int OneD::getX()
{
    return x;
}

//distance between 2 1-d points
void OneD::CalcDistance(OneD PointTwo)
{
    cout << "The distance between the points is: " << sqrt((x-PointTwo.getX())*(x-PointTwo.getX()));
}
