/*Jonathan Brashears
* 9/26/2016
* CS 102
* Homework 3
* Reads a file of transactions, calculates total, and accepts payment
*/
#ifndef STOREITEM_H_INCLUDED
#define STOREITEM_H_INCLUDED
#include <iostream>
#include <string>
#include <iomanip>
//#include "Register.h"
using namespace std;

class storeItem{
    private:
        double MSRP; //price before discount
        double discount; //discount percent
        string ItemName; //name of item
        double price; //Holds price after discount
        void calculatePrice(); //function to calculate price
    public:
        storeItem();
        void itemInfo(string, double); //setters
        void setDiscount(double);
        double getPrice(); //getters
        double getMSRP();
        string getItemName();
};

#endif // CLASSES_H_INCLUDED
