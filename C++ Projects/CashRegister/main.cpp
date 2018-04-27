/*Jonathan Brashears
* 9/26/2016
* CS 102
* Homework 3
* Reads a file of transactions, calculates total, and accepts payment
*/

#include <iostream>
#include <fstream>
#include <string>
#include "storeItem.h"
#include "Register.h"
using namespace std;

string fileName; //holds user input filename
string name; //holds name of item to be passed to class
double initialCash = 0.00; //initial cash in register
double scanPrice = 0.00; //the price of the scanned item
double discountPercent = 0.00; //discount percent
storeItem transactions[300]; //array of class object storeItem
Register registerTest; //Register
char inputCheck; //Holds char from first line of file
int counter = 0; //counter

//reads the file
void readFile()
{
    ifstream infile;

    cout << "Files Test1.txt, Test2.txt, Test3.txt, and Test4.txt are available." << endl << "Please input which file you would like to read. " << endl;  //asks user to input filename
    cin >> fileName; //Gets filename from user

    infile.open(fileName.c_str()); //Opens the file the user input

    while(infile.good()) //reads file and assigns to values and passes to storeItem
    {
        infile >> inputCheck;
        while (inputCheck == 'R')  //if first line is R it is passed to register
        {
            infile >> initialCash >> inputCheck;
            registerTest = Register(initialCash);
        }

        infile >> name >> scanPrice >> discountPercent; //sends values from file to variables
        transactions[counter].itemInfo(name, scanPrice); //should pass to class storeItem
        transactions[counter].setDiscount(discountPercent); //should pass to class storeItem

        counter++; //increments counter
    }

    infile.close();
}



int main()
{

    readFile ();
    for (int i = 0; i < counter; i++) //Checks for correct price after discount
    {
        transactions[i].getPrice();
    }

    registerTest.scanItem(transactions, counter); //calls scan item
    cout << "Total: ";
    cout << registerTest.getTransactionTotal() << endl; //calls for total calculation
    registerTest.acceptCash(); //accepts cash
    registerTest.printReceipt(transactions, counter); //prints customer receipt
    cout << endl << "Register Balance: "; //displays amount in register after transaction
    cout << registerTest.registerBalance();
    cin.get();
    cin.get();
    return 0;
}
