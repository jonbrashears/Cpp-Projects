/*  Jonathan Brashears
    Homework 4
    CS 102
    Distance Calculator
*/
#include <iostream>
#include <cmath>
#include "OneD.h"

using namespace std;

//Interface for TwoD class
#ifndef TWOD_H_INCLUDED
#define TWOD_H_INCLUDED
class TwoD : public OneD
{
    protected:
       int y; //holds y coordinate
   public:
        TwoD(); //default constructor
        TwoD(int x, int y); //sets x and y
        int getY(); //gets y
        void CalcDistance(OneD); //calculates distance between 2-d and 1-d point
        void CalcDistance(TwoD); //calculates distance between 2 2-d points
};


#endif // TWOD_H_INCLUDED
