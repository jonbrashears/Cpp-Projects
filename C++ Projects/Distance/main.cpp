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

int CoordOne = 0; //1-d coordinate
int CoordTwo = 0; //2-d coordinate
int CoordThree = 0; //3-d coordinate
OneD PointOne; //first point class
OneD PointTwo; //second point class

//Distance between 2 1-dimensional points
void testOneD()
{
    cout << "Please enter the fist 1-dimensional point" << endl;  //asks for user to input first point
    cin >> CoordOne;
    PointOne = OneD(CoordOne);  //Creates class with that point
    cout << "Please enter the second 1-dimensional point" << endl; //asks user to input second point
    cin >> CoordOne;

    PointTwo = OneD(CoordOne);  //creates class with that point
    PointOne.CalcDistance(PointTwo); //calculates distance between the two points
}

//tests between two 2-d points
void testTwoD()
{
    cout << endl << "Please enter the x coordinate of a 2-dimensional point" << endl; //asks for user to input first point
    cin >> CoordOne;
    cout << "Please enter the y coordinate of the point" << endl;
    cin >> CoordTwo;

    TwoD PointOne;
    PointOne = TwoD(CoordOne, CoordTwo); //creates class from first point

    cout << endl << "Please enter the x coordinate of another 2-dimensional point" << endl; //asks for user to input second point
    cin >> CoordOne;
    cout << endl << "Please enter the y coordinate of the point" << endl;
    cin >> CoordTwo;
    cout << endl;

    TwoD PointTwo;
    PointTwo = TwoD(CoordOne, CoordTwo);  //creates class from second point

    PointOne.CalcDistance(PointTwo);  //calculates distance between these points
}

//Tests 3-d point from 1-d point
void testThreeD()
{
    cout << endl << "Please enter the x coordinate of a 3-dimensional point" << endl;  //asks for user to input a 3-d point
    cin >> CoordOne;
    cout << endl << "Please enter the y coordinate of the point" << endl;
    cin >> CoordTwo;
    cout << endl << "Please enter the z coordinate of the point" << endl;
    cin >> CoordThree;
    cout << endl;

    ThreeD PointOne;
    PointOne = ThreeD(CoordOne, CoordTwo, CoordThree);  //creates 3-d class

    cout << endl << "Please enter the x coordinate of a 1-dimensional point" << endl;  //asks user for 1-d point
    cin >> CoordOne;

    OneD PointTwo;
    PointTwo = OneD(CoordOne);  //creates 1-d class

    PointOne.CalcDistance(PointTwo); //calculates the distance between the 2

}

int main()
{
    //Calls test functions
    testOneD();
    testTwoD();
    testThreeD();

}
