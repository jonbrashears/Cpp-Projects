/*
 * Jonathan Brashears
 * 11/1/16
 * Homework 5
 * Reads values from file and stores them in a dynamic array.  The array can then be manipulated in multiple ways
 */


#include <iostream>
#include <fstream>
#include <string>

#include "items.h"

using namespace std;

int index = 0;

string fileName;

void readFileInt(Items <int>& FirstList, int value);
void readFileFloat(Items <float>& FirstList, float value);
void readFileDouble(Items <double>& FirstList, double value);


int main()
{
    string dataCheck;

    cout << "What type of value are stored in the files? (int, float, or double)" << endl;
    cin >> dataCheck;
    if (dataCheck == "int")
    {
        int value = 0;
        Items <int> FirstList;
        Items <int> SecondList;
        readFileInt(FirstList, value);
        readFileInt(SecondList, value);
        cout << endl;

        FirstList << SecondList;
        cout << endl << "The union of the two collections is: ";
        FirstList + SecondList;

        cout << endl;

        cout << "The intersect of the two collections is: ";
        FirstList - SecondList;

        cout << endl;

        cout << "The relative complement of the two collections is: ";
        FirstList / SecondList;

        cout << endl;

        cout << "The cartesian product of the two collections is: ";
        FirstList* SecondList;

        cout << endl;

        FirstList << SecondList;

        cout << endl;
    }
    else if (dataCheck == "float")
    {
        float value = 0;
        Items <float> FirstList;
        Items <float> SecondList;
        readFileFloat(FirstList, value);
        readFileFloat(SecondList, value);
        cout << endl;

        cout << "The union of the two collections is: ";
        FirstList + SecondList;

        cout << endl;

        cout << "The intersect of the two collections is: ";
        FirstList - SecondList;

        cout << endl;

        cout << "The relative complement of the two collections is: ";
        FirstList / SecondList;

        cout << endl;

        cout << "The cartesian product of the two collections is: ";
        FirstList* SecondList;

        cout << endl;

        FirstList << SecondList;

        cout << endl;
    }
    else if (dataCheck == "double")
    {
        double value = 0;
        Items <double> FirstList;
        Items <double> SecondList;
        readFileDouble(FirstList, value);
        readFileDouble(SecondList, value);
        cout << endl;

        cout << "The union of the two collections is: ";
        FirstList + SecondList;

        cout << endl;

        cout << "The intersect of the two collections is: ";
        FirstList - SecondList;

        cout << endl;

        cout << "The relative complement of the two collections is: ";
        FirstList / SecondList;

        cout << endl;

        cout << "The cartesian product of the two collections is: ";
        FirstList* SecondList;

        cout << endl;

        FirstList << SecondList;

        cout << endl;
    }
    else
    {
        cout << "Please enter a valid datatype. " << endl;
        cin >> dataCheck;
    }

}

//reads items from first file
void readFileInt(Items <int>& List, int value)
{
    ifstream infile;

    //Gets filename from user
    cout << "Please input which file you would like to read. " << endl; 
    cin >> fileName;                    

    //Opens the file the user input
    infile.open(fileName.c_str());     

    //Checks to see if file is there
    while (!infile.good())
    {
        cout << endl << "File not found.  Please enter a valid file name. " << endl;
        cin >> fileName;
        infile.open(fileName.c_str());
    }
    while (infile.good())   //reads file and assigns to values and passes to storeItem
    {
        infile >> value;    //sets current line being read to value
        List.add(value);    //adds value to the array
    }

}
void readFileFloat(Items <float>& List, float value)
{
    ifstream infile;

    // Gets filename from user
    cout << "Please input which file you would like to read. " << endl;
    cin >> fileName;                                                    

    // Opens the file the user input
    infile.open(fileName.c_str()); 

    // Checks to see if file is there
    while (!infile.good())
    {
        cout << endl << "File not found.  Please enter a valid file name. " << endl;
        cin >> fileName;
        infile.open(fileName.c_str());
    }
    while (infile.good())   // reads file and assigns to values and passes to storeItem
    {
        infile >> value;    // sets current line being read to value
        List.add(value);    // adds value to the array
    }

}

void readFileDouble(Items <double>& List, double value)
{
    ifstream infile;

    // Gets filename from user
    cout << "Please input which file you would like to read. " << endl;
    cin >> fileName; 

    // Opens the file the user input
    infile.open(fileName.c_str()); 

    // Checks to see if file is there
    while (!infile.good())
    {
        cout << endl << "File not found.  Please enter a valid file name. " << endl;
        cin >> fileName;
        infile.open(fileName.c_str());
    }
    while (infile.good())   // reads file and assigns to values and passes to storeItem
    {
        infile >> value;    // sets current line being read to value
        List.add(value);    // adds value to the array
    }

}