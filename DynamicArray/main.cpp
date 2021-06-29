/*
Jonathan Brashears
11/8/16
Homework 6
Reads values from two file and stores them in a dynamic arrays.  The array can then be manipulated in multiple ways. Overloaded operators allow the performance of set arithmetic
Note: Tried to use templates to allow the use of doubles and floats, but I could not get the dynamic array working inside of the template.
*/
#include <iostream>
#include <fstream>
#include <string>
#include "collection.h"
#include "items.h"

using namespace std;

int value = 0;  //holds current value being read from file
int index = 0; //holds the current index the user is interacting with
string fileName; //holds name of file to be read
Items FirstList; //class of items
Items SecondList;


//reads items from first file
void readFileOne()
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

//reads items from first file
void readFileTwo()
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
readFileOne(); //reads first file
readFileTwo(); //reads second file
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
/*cout << "What index would you like to view? " << endl;//asks user which element of the array they want to view
cin >> index;   //user input index to view
cout << FirstList.get(index); //displays index to user
cout << endl << "The values of the array are: ";
FirstList.print();  //prints the array
cout << endl << "The sum of the items is: ";
cout << FirstList.sum() << endl;// prints sum of the values in the array
cout << "There are ";
cout << FirstList.size();  //outputs size of the array
cout << " items in the array." << endl;
cout << "Which item do you wish to remove from the array?" <<endl;
cin >> index;  //holds item to be removed from the array
FirstList.remove(index);  //removes item from array
cout << endl << "The new array is: ";
FirstList.print(); //prints the array after the elements is deleted*/
}
