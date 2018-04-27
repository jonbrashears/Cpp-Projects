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

//interface for ThreeD class
#ifndef THREED_H_INCLUDED
#define THREED_H_INCLUDED
class ThreeD : public TwoD
{
    protected:
        int z; //holds z value

    public:
        ThreeD(); //constructor
        ThreeD(int CoordOne, int CoordTwo, int CoordThree); //sets x,y,and z
        int getZ(); //Return Z;
        void CalcDistance(OneD PointTwo); // OVERRIDE: Calculates the distance between the 3d instance and a 1d point.
        void CalcDistance(TwoD PointTwo); // OVERRIDE: Calculates the distance between the 2d instance and 2D point.
        void CalcDistance(ThreeD PointTwo); //Calculates the distance between the instance and 3d point.
};


#endif // THREED_H_INCLUDED
