/*Jonathan Brashears
* 9/26/2016
* CS 102
* Homework 3
* Reads a file of transactions, calculates total, and accepts payment
*/
#include <string>
#include <iomanip>
#include <iostream>
#include "Register.h"
#include "storeItem.h"

using namespace std;


//Functions for Register
//Default constructor for Register
Register::Register()
{
    cashInRegister = 400.00;
    total = 0.00;
    change = 0.00;
    payment = 0.00;
}

//Constructor for Register
Register::Register(double initialCash)
{
    cashInRegister = initialCash;
}

//Finds total before tax
void Register::scanItem(storeItem transactions[300], int counter)
{
    for (int i=0; i < counter; i++)
    {
        total += transactions[i].getPrice();
    }
    total*=1.07;
}

//Returns total
double Register::getTransactionTotal()
{
    return total;
}

//Calculates amount in register
double Register::registerBalance()
{
    cashInRegister += total;
    return cashInRegister;
}

//Asks customer for payment and change
double Register::acceptCash()
{
    cout << "How much did the customer pay with?" << endl;
    cin >> payment;
    change = payment - total;
    return change;
}

//Prints the customers receipt
void Register::printReceipt(storeItem transactions[300], int counter)
{
    cout << endl << "RECEIPT" << endl;
    for(int i = 0; i < counter; i++) //loop to print items and their cost after discounts
    {
        cout << fixed << setprecision(2) << transactions[i].getItemName() << "\t\t";
        cout << setprecision(2) << transactions[i].getPrice() << endl;
    }
    cout << fixed << setprecision(2) << endl << "Total: " << "\t\t" << total << endl ;
    cout << setprecision(2) << "Cash tendered: " << "\t"<< payment << endl;
    cout << setprecision(2) << "Change: " << "\t"<< change << endl;
}
