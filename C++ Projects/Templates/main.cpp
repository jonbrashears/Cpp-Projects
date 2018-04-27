/*
Jonathan Brashears
11/1/16
Homework 5
Reads values from file and stores them in a dynamic array.  The array can then be manipulated in multiple ways
*/
#include <iostream>
#include <fstream>
#include <string>

#include "items.h"

using namespace std;


int index = 0; //holds the current index the user is interacting with
string fileName; //holds name of file to be read


//reads items from first file
void readFileOneInt(Items <int> FirstList, int value)
{
    ifstream infile;

    cout << "Please input which file you would like to read. " << endl;  //asks user to input filename
    cin >> fileName; //Gets filename from user

    infile.open(fileName.c_str()); //Opens the file the user input

    //Checks to see if file is there
    while (!infile.good())
    {
        cout << endl << "File not found.  Please enter a valid file name. " << endl;
        cin >> fileName;
        infile.open(fileName.c_str());
    }
    while(infile.good()) //reads file and assigns to values and passes to storeItem
    {
        infile >> value; //sets current line being read to value
        FirstList.add(value); //adds value to the array
    }

}
void readFileOneFloat(Items <float> FirstList, float value)
{
    ifstream infile;

    cout << "Please input which file you would like to read. " << endl;  //asks user to input filename
    cin >> fileName; //Gets filename from user

    infile.open(fileName.c_str()); //Opens the file the user input

    //Checks to see if file is there
    while (!infile.good())
    {
        cout << endl << "File not found.  Please enter a valid file name. " << endl;
        cin >> fileName;
        infile.open(fileName.c_str());
    }
    while(infile.good()) //reads file and assigns to values and passes to storeItem
    {
        infile >> value; //sets current line being read to value
        FirstList.add(value); //adds value to the array
    }

}

void readFileOneDouble(Items <double> FirstList, double value)
{
    ifstream infile;

    cout << "Please input which file you would like to read. " << endl;  //asks user to input filename
    cin >> fileName; //Gets filename from user

    infile.open(fileName.c_str()); //Opens the file the user input

    //Checks to see if file is there
    while (!infile.good())
    {
        cout << endl << "File not found.  Please enter a valid file name. " << endl;
        cin >> fileName;
        infile.open(fileName.c_str());
    }
    while(infile.good()) //reads file and assigns to values and passes to storeItem
    {
        infile >> value; //sets current line being read to value
        FirstList.add(value); //adds value to the array
    }

}
//reads items from Second file
void readFileTwoInt(Items <int> SecondList, int value)
{
    ifstream infile;

    cout << "Please input which file you would like to read. " << endl;  //asks user to input filename
    cin >> fileName; //Gets filename from user

    infile.open(fileName.c_str()); //Opens the file the user input

    //Checks to see if file is there
    while (!infile.good())
    {
        cout << endl << "File not found.  Please enter a valid file name. " << endl;
        cin >> fileName;
        infile.open(fileName.c_str());
    }
    while(infile.good()) //reads file and assigns to values and passes to storeItem
    {
        infile >> value; //sets current line being read to value
        SecondList.add(value); //adds value to the array
    }

}

void readFileTwoFloat(Items <float> SecondList, float value)
{
    ifstream infile;

    cout << "Please input which file you would like to read. " << endl;  //asks user to input filename
    cin >> fileName; //Gets filename from user

    infile.open(fileName.c_str()); //Opens the file the user input

    //Checks to see if file is there
    while (!infile.good())
    {
        cout << endl << "File not found.  Please enter a valid file name. " << endl;
        cin >> fileName;
        infile.open(fileName.c_str());
    }
    while(infile.good()) //reads file and assigns to values and passes to storeItem
    {
        infile >> value; //sets current line being read to value
        SecondList.add(value); //adds value to the array
    }

}

void readFileTwoDouble(Items <double> SecondList, double value)
{
    ifstream infile;

    cout << "Please input which file you would like to read. " << endl;  //asks user to input filename
    cin >> fileName; //Gets filename from user

    infile.open(fileName.c_str()); //Opens the file the user input

    //Checks to see if file is there
    while (!infile.good())
    {
        cout << endl << "File not found.  Please enter a valid file name. " << endl;
        cin >> fileName;
        infile.open(fileName.c_str());
    }
    while(infile.good()) //reads file and assigns to values and passes to storeItem
    {
        infile >> value; //sets current line being read to value
        SecondList.add(value); //adds value to the array
    }

}
int main()
{
    string dataCheck;

    cout << "What type of value are stored in the files? (int, float, or double)" << endl;
    cin >> dataCheck;
    if(dataCheck == "int")
    {
        int value = 0;
        Items <int> FirstList;
        Items <int> SecondList;
        readFileOneInt(FirstList, value);
        readFileTwoInt(SecondList, value);
    cout << endl;

    FirstList<<SecondList;
    cout << endl << "The union of the two collections is: ";
    FirstList + SecondList;

    cout << endl;

    cout << "The intersect of the two collections is: ";
    FirstList - SecondList;

    cout << endl;

    cout << "The relative complement of the two collections is: ";
    FirstList/SecondList;

    cout << endl;

    cout << "The cartesian product of the two collections is: ";
    FirstList*SecondList;

    cout << endl;

    FirstList<<SecondList;

    cout << endl;
    }

    else if (dataCheck == "float")
    {
        float value = 0;
        Items <float> FirstList;
        Items <float> SecondList;
        readFileOneFloat(FirstList, value);
        readFileTwoFloat(SecondList, value);
            cout << endl;

    cout << "The union of the two collections is: ";
    FirstList + SecondList;

    cout << endl;

    cout << "The intersect of the two collections is: ";
    FirstList - SecondList;

    cout << endl;

    cout << "The relative complement of the two collections is: ";
    FirstList/SecondList;

    cout << endl;

    cout << "The cartesian product of the two collections is: ";
    FirstList*SecondList;

    cout << endl;

    FirstList<<SecondList;

    cout << endl;
    }
    else if (dataCheck == "double")
    {
        double value = 0;
        Items <double> FirstList;
        Items <double> SecondList;
        readFileOneDouble(FirstList, value);
        readFileTwoDouble(SecondList, value);
            cout << endl;

    cout << "The union of the two collections is: ";
    FirstList + SecondList;

    cout << endl;

    cout << "The intersect of the two collections is: ";
    FirstList - SecondList;

    cout << endl;

    cout << "The relative complement of the two collections is: ";
    FirstList/SecondList;

    cout << endl;

    cout << "The cartesian product of the two collections is: ";
    FirstList*SecondList;

    cout << endl;

    FirstList<<SecondList;

    cout << endl;
    }
    else
    {
        cout << "Please enter a valid datatype. " << endl;
        cin >> dataCheck;
    }

}
