/*  Jonathan Brashears
    Homework 4
    CS 102
    Distance Calculator
*/
#include <iostream>
#include <cmath>
using namespace std;

//Interface of OneD class
#ifndef ONED_H_INCLUDED
#define ONED_H_INCLUDED
class OneD
{
    protected:
        int x; //holds first coordinate

    public:
        OneD();
        OneD(int); //sets x
        int getX(); //return x
        void CalcDistance(OneD); //Calculates the distance between the instance and 1d point.
};


#endif // ONED_H_INCLUDED
