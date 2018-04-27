/*Jonathan Brashears
* 9/26/2016
* CS 102
* Homework 3
* Reads a file of transactions, calculates total, and accepts payment
*/
#ifndef REGISTER_H_INCLUDED
#define REGISTER_H_INCLUDED
#include <iostream>
#include <string>
#include <iomanip>
#include "storeItem.h"

using namespace std;

class Register {
    private:
        double cashInRegister; //holds amount of cash in register
        double total; //holds total
        double change; //holds change
        double payment; //holds user payment

    public:
        Register(); //default constructor
        Register(double); //constructor
        void scanItem(storeItem[],int); //calculates transaction
        double registerBalance(); //calculates amount in register after purchase
        double getTransactionTotal(); //total amount customer owes
        double acceptCash(); //accept payments from user and calculates change
        void printReceipt(storeItem[], int); //prints values
};
#endif // REGISTER_H_INCLUDED
