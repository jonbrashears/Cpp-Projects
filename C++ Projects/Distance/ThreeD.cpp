/*  Jonathan Brashears
    Homework 4
    CS 102
    Distance Calculator
*/
#include <iostream>
#include <cmath>
#include "OneD.h"
#include "TwoD.h"
#include "ThreeD.h"

using namespace std;

//constructor
ThreeD::ThreeD()
{
    x = 0;  //holds x
    y = 0;  //holds y
    z = 0;  //holds z
}

//constructor that sets x,y,z from user input
ThreeD::ThreeD(int CoordOne, int CoordTwo, int CoordThree)
{
    x = CoordOne;   //user input x
    y = CoordTwo;   //user input y
    z = CoordThree; //user input z
}

//getter
int ThreeD::getZ()
{
    return z; //returns z
}

//calculates distance between 3-d and 1-d point
void ThreeD::CalcDistance(OneD PointTwo)
{
    cout << "The distance between the points is: " << sqrt(((x - PointTwo.getX())*(x - PointTwo.getX()))+(y*y)+(z*z));
}

//calculates distance between 3-d and 2-d point
void ThreeD::CalcDistance(TwoD PointTwo)
{
    cout << "The distance between the points is: " << sqrt((x-PointTwo.getX())*(x-PointTwo.getX())+(y-PointTwo.getY())*(y-PointTwo.getY())+(z*z));
}
//calculates distance between two 3-d points
void ThreeD::CalcDistance(ThreeD PointTwo)
{
    cout << "The distance between the points is: " << sqrt((x-PointTwo.getX())*(x-PointTwo.getX())+(y-PointTwo.getY())*(y-PointTwo.getY())+(z-PointTwo.getZ())*(z-PointTwo.getZ()));
}
